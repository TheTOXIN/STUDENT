// Originally written by John Batte
// Modifications, API changes and cleanups by Phil Crosby

using System;
using System.IO;
using System.Net;

namespace EPS.Libraries.ClientLibrary.HttpUtils
{
	public class FileDownloader
	{
		static string TEMP_DIR
		{
			get
			{
				string localTemp = Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData);
				localTemp = System.IO.Path.Combine(localTemp, "EPS-FileDownloader");
				
				if(!Directory.Exists(localTemp))
					Directory.CreateDirectory(localTemp);

				return localTemp;
			}
		}
		public static string DownloaderTempDirectory
		{
			get
			{
				return TEMP_DIR;
			}
		}
		// to adjust how many bytes are read from the url at a time,
		// simply change this constant:
		private const int downloadBlockSize = 1024;

		// Determines whether the user has canceled or not.
		private bool canceled = false;

		private bool paused = false;

		private string downloadingTo;

		/// <summary>
		/// This is the name of the file we get back from the server when we
		/// try to download the provided url. It will only contain a non-null
		/// string when we've successfully contacted the server and it has started
		/// sending us a file.
		/// </summary>
		public string DownloadingTo
		{
			get { return downloadingTo; }
		}

		public void Cancel()
		{
			this.canceled = true;
		}

		public FileDownloader()
		{
			// * make all WebRequests use the same Proxy info that IE uses.
			// * These methods are deprecated in .net 2.0
			//GlobalProxySelection.Select = WebProxy.GetDefaultProxy();
			//GlobalProxySelection.Select.Credentials = CredentialCache.DefaultCredentials;
		}

		/// <summary>
		/// Progress update
		/// </summary>
		public event DownloadProgressHandler ProgressChanged;
		/// <summary>
		/// A change in the state of the donwload, e.g. if the server cancels the transmission
		/// </summary>
		public event DownloadProgressHandler StateChanged;
		/// <summary>
		/// Fired when progress reaches 100%.
		/// </summary>
		public event EventHandler DownloadComplete;

		private void OnDownloadComplete()
		{
			if (this.DownloadComplete != null)
				this.DownloadComplete(this, new EventArgs());
		}

		/// <summary>
		/// Begin downloading the file at the specified url, and save it to the current folder.
		/// </summary>
		public void Download(string url)
		{
			Download(url, "");
		}
		/// <summary>
		/// Begin downloading the file at the specified url, and save it to the given folder.
		/// </summary>
		public void Download(string url, string destFolder)
		{
			DownloadData data = null;
			this.canceled = false;

			try
			{
				if (canceled)
					return;

				if(destFolder != null & destFolder != string.Empty)
				{
					if(!Directory.Exists(Path.GetDirectoryName(destFolder)))
						Directory.CreateDirectory(Path.GetDirectoryName(destFolder));
				}

				// get download details
				data = DownloadData.Create(url, destFolder);

				// Find out the name of the file that the web server gave us.
				string destFileName = Path.GetFileName(data.Response.ResponseUri.ToString());
				if(Path.GetDirectoryName(destFolder) == destFolder)
					this.downloadingTo = Path.GetFullPath(Path.Combine(destFolder, destFileName));
				else
					this.downloadingTo = destFolder;
				

				// send the new download state
				RaiseStateChanged(data.DownloadState);

				// create the download buffer
				byte[] buffer = new byte[downloadBlockSize];

				int readCount;

				// update how many bytes have already been read
				long totalDownloaded = data.StartPoint;

				bool gotCanceled = false;
				// read a block of bytes and get the number of bytes read
				while ((int)(readCount = data.DownloadStream.Read(buffer, 0, downloadBlockSize)) > 0)
				{
					// break on cancel
					if (canceled)
					{
						gotCanceled = true;
						data.Close();
						break;
					}
					//pause on pause
					while(paused)
					{
						System.Threading.Thread.Sleep(50);
						System.Windows.Forms.Application.DoEvents();
					}

					// update total bytes read
					totalDownloaded += readCount;

					// save block to end of file
					SaveToFile(buffer, readCount, this.downloadingTo);

					// send progress info
					if (data.IsProgressKnown)
						RaiseProgressChanged(totalDownloaded, data.FileSize);

					// break on cancel
					if (canceled)
					{
						gotCanceled = true;
						break;
					}
				}

				if (!gotCanceled)
					OnDownloadComplete();
			}
			finally
			{
				if (data != null)
					data.Close();
			}
		}
		public void Pause()
		{
			paused = true;
		}

		public void Resume()
		{
			paused = false;
		}
		/// <summary>
		/// Download a file from the url asynchronously.
		/// </summary>
		public void AsyncDownload(string url)
		{
			System.Threading.ThreadPool.QueueUserWorkItem(
				new System.Threading.WaitCallback(this.WaitCallbackMethod), new string[] { url, "" });
		}
		/// <summary>
		/// Download a file from the url to the destination folder asynchronously.
		/// </summary>
		public void AsyncDownload(string url, string destFolder)
		{
			System.Threading.ThreadPool.QueueUserWorkItem(
				new System.Threading.WaitCallback(this.WaitCallbackMethod), new string[] { url, destFolder });
		}
		/// <summary>
		/// A WatCallback used by the AsyncDownload methdos.
		/// </summary>
		private void WaitCallbackMethod(object data)
		{
			// Expecting an array of two strings (url and dest folder)
			String[] strings = data as String[];
			this.Download(strings[0], strings[1]);
		}

		private void RaiseStateChanged(string state)
		{
			if (this.StateChanged != null)
				this.StateChanged(this, new DownloadEventArgs(state));
		}
		private void SaveToFile(byte[] buffer, int count, string fileName)
		{
			FileStream f = null;

			try
			{
				f = File.Open(fileName, FileMode.Append, FileAccess.Write);
				f.Write(buffer, 0, count);
			}
			catch (ArgumentException e)
			{
				throw new ArgumentException(
					String.Format("Error trying to save file \"{0}\": {1}", fileName, e.Message), e);
			}
			finally
			{
				if (f != null)
					f.Close();
			}
		}
		private void RaiseProgressChanged(long current, long target)
		{
			if (this.ProgressChanged != null)
				this.ProgressChanged(this, new DownloadEventArgs(target, current));
		}
	}

	public class DownloadData
	{
		private HttpWebResponse response;

		public HttpWebResponse Response
		{
			get { return response; }
			set { response = value; }
		}

		private Stream stream;
		private long size;
		private long start;
		private bool progressKnown;

		public static DownloadData Create(string url, string destFolder)
		{
			bool progressKnown;
			bool resume = false;
			long urlSize = GetFileSize(url, out progressKnown);
			long startPoint = 0;
			
			HttpWebRequest req = GetRequest(url);
			HttpWebResponse response;
			
			try
			{
				response = (HttpWebResponse)req.GetResponse();
			}
			catch (Exception e)
			{
				throw new ArgumentException(String.Format(
					"Error downloading \"{0}\": {1}", url, e.Message), e);
			}

			// If it's an HTML page, it's probably an error page. Comment this
			// out to enable downloading of HTML pages.
			if ((response.ContentType.IndexOf("text/html") > -1) || response.StatusCode == HttpStatusCode.NotFound)
			{

				throw new ArgumentException(
					String.Format("Couldn't download \"{0}\" - a web page was returned from the web server.",
					url));
			}

			// Take the name of the file given to use from the web server.
			String fileName = System.IO.Path.GetFileName(response.ResponseUri.ToString());

			String downloadTo = string.Empty; //Path.Combine(destFolder, fileName);
			if(Path.GetDirectoryName(destFolder) == destFolder)
				downloadTo = Path.GetFullPath(Path.Combine(destFolder, fileName));
			else
				downloadTo = destFolder;

			if (progressKnown && File.Exists(downloadTo))
			{
				startPoint = new FileInfo(downloadTo).Length;
				// If we have a file that's bigger than what is online, then something 
				// strange happened. Delete it and start again.
				if (startPoint > urlSize)
					File.Delete(downloadTo);
				else if (startPoint < urlSize)
				{
					resume = true;
					req.AddRange((int)startPoint);
				}
			}
			else if (File.Exists(downloadTo))
				File.Delete(downloadTo);

			// If we're resuming, make a new request that includes how much we're already got
			if (resume)
			{
				response.Close();
				req = GetRequest(url);
				req.AddRange((int)startPoint);
				response = (HttpWebResponse)req.GetResponse();
			}

			// If we don't get a status code of PartialContent, they didn't support our resume request.
			if (resume && response.StatusCode != HttpStatusCode.PartialContent)
			{
				File.Delete(downloadTo);
				startPoint = 0;
			}

			return new DownloadData(response, urlSize, startPoint, progressKnown);
		}

		public static long GetFileSize(string url, out bool progressKnown)
		{
			HttpWebResponse response = null;
			long size = -1;

			try
			{
				response = (HttpWebResponse)GetRequest(url).GetResponse();

				size = response.ContentLength;

				if (size == -1)
					progressKnown = false;
				else
					progressKnown = true;
			}
			finally
			{
				if (response != null)
					response.Close();
			}

			return size;
		}

		private static HttpWebRequest GetRequest(string url)
		{
			HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
			request.Credentials = CredentialCache.DefaultCredentials;
			return request;
		}

		private DownloadData(HttpWebResponse response, long size, long start, bool progressKnown)
		{
			this.response = response;
			this.size = size;
			this.start = start;
			this.stream = null;
			this.progressKnown = progressKnown;
		}

		public Stream DownloadStream
		{
			get
			{
				if (this.start == this.size)
					return Stream.Null;
				if (this.stream == null)
					this.stream = this.response.GetResponseStream();
				return this.stream;
			}
		}

		public long FileSize
		{
			get
			{
				return this.size;
			}
		}

		public long StartPoint
		{
			get
			{
				return this.start;
			}
		}

		public string DownloadState
		{
			get
			{

				return this.response.StatusCode.ToString();

			}
		}

		public bool IsProgressKnown
		{
			get
			{
				return this.progressKnown;
			}
		}

		public void Close()
		{
			this.response.Close();
		}
	}

	/// <summary>
	/// Progress of a downloading file.
	/// </summary>
	public class DownloadEventArgs : EventArgs
	{
		private int percentDone;
		private string downloadState;
		private long totalFileSize;

		public long TotalFileSize
		{
			get { return totalFileSize; }
			set { totalFileSize = value; }
		}
		private long currentFileSize;

		public long CurrentFileSize
		{
			get { return currentFileSize; }
			set { currentFileSize = value; }
		}

		public DownloadEventArgs(long totalFileSize, long currentFileSize)
		{
			this.totalFileSize = totalFileSize;
			this.currentFileSize = currentFileSize;

			this.percentDone = (int)((((double)currentFileSize) / totalFileSize) * 100);
		}

		public DownloadEventArgs(string state)
		{
			this.downloadState = state;
		}

		public DownloadEventArgs(int percentDone, string state)
		{
			this.percentDone = percentDone;
			this.downloadState = state;
		}

		public int PercentDone
		{
			get
			{
				return this.percentDone;
			}
		}

		public string DownloadState
		{
			get
			{
				return this.downloadState;
			}
		}
	}

	public delegate void DownloadProgressHandler(object sender, DownloadEventArgs e);
}