using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.IO;

namespace EPS.Libraries.ClientLibrary.HttpUtils
{
	public enum DownloadStatus
	{
		Downloading,
		Completed,
		Failed,
		Canceled
	}
	/// <summary>
	/// Summary description for DownloadSqlForm.
	/// </summary>
	public class FileDownloaderForm : System.Windows.Forms.Form
	{
		bool unattended = false;
		private DownloadURLCollection urls = null;
		private long[] sizes  = null;
		private bool canceled = false;
		private DownloadStatus status = DownloadStatus.Downloading;
		//total size for all files
		private long totalSize = 0;
		//last known file size
		long lastSize = 0;
		//total downloaded for ALL files being downloaded
		long completedSize = 0;
		//maximum text length for a url on the form
		const int MAX_URL_LENGTH = 69;
		const int MAX_TEMP_DIR_LENGTH = 75;

		
		private FileDownloader downloader;
		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.ProgressBar prgOverall;
		private System.Windows.Forms.ProgressBar prgCurrent;
		private System.Windows.Forms.Label lblCurrentFile;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Button btnCancel;
		private System.Windows.Forms.Button btnPause;
		private System.Windows.Forms.Label lblCurrentComplete;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label lblOverallComplete;
		private System.Windows.Forms.Label lblCurrentPercent;
		private System.Windows.Forms.Label lblOverallPercent;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Label lblDownlaodingTo;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public FileDownloaderForm(DownloadURLCollection urls):this(urls, false)
		{
		}
		public FileDownloaderForm(DownloadURLCollection urls, bool unattended)
		{
			InitializeComponent();

			this.urls = urls;
			downloader = new FileDownloader();
			this.unattended = unattended;
			FileDownloaderForm.DownloaderExceptionManager.Initialize(this);
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if(components != null)
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.lblDownlaodingTo = new System.Windows.Forms.Label();
			this.lblOverallPercent = new System.Windows.Forms.Label();
			this.prgOverall = new System.Windows.Forms.ProgressBar();
			this.label3 = new System.Windows.Forms.Label();
			this.prgCurrent = new System.Windows.Forms.ProgressBar();
			this.lblCurrentFile = new System.Windows.Forms.Label();
			this.label1 = new System.Windows.Forms.Label();
			this.lblCurrentComplete = new System.Windows.Forms.Label();
			this.lblOverallComplete = new System.Windows.Forms.Label();
			this.lblCurrentPercent = new System.Windows.Forms.Label();
			this.label4 = new System.Windows.Forms.Label();
			this.btnCancel = new System.Windows.Forms.Button();
			this.btnPause = new System.Windows.Forms.Button();
			this.label2 = new System.Windows.Forms.Label();
			this.groupBox1.SuspendLayout();
			this.SuspendLayout();
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.lblDownlaodingTo);
			this.groupBox1.Controls.Add(this.lblOverallPercent);
			this.groupBox1.Controls.Add(this.prgOverall);
			this.groupBox1.Controls.Add(this.label3);
			this.groupBox1.Controls.Add(this.prgCurrent);
			this.groupBox1.Controls.Add(this.lblCurrentFile);
			this.groupBox1.Controls.Add(this.label1);
			this.groupBox1.Controls.Add(this.lblCurrentComplete);
			this.groupBox1.Controls.Add(this.lblOverallComplete);
			this.groupBox1.Controls.Add(this.lblCurrentPercent);
			this.groupBox1.Controls.Add(this.label4);
			this.groupBox1.FlatStyle = System.Windows.Forms.FlatStyle.System;
			this.groupBox1.Location = new System.Drawing.Point(12, 8);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(536, 172);
			this.groupBox1.TabIndex = 0;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "Download Progress";
			// 
			// lblDownlaodingTo
			// 
			this.lblDownlaodingTo.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
			this.lblDownlaodingTo.Location = new System.Drawing.Point(100, 148);
			this.lblDownlaodingTo.Name = "lblDownlaodingTo";
			this.lblDownlaodingTo.Size = new System.Drawing.Size(420, 20);
			this.lblDownlaodingTo.TabIndex = 9;
			this.lblDownlaodingTo.TextAlign = System.Drawing.ContentAlignment.BottomLeft;
			// 
			// lblOverallPercent
			// 
			this.lblOverallPercent.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
			this.lblOverallPercent.Location = new System.Drawing.Point(484, 84);
			this.lblOverallPercent.Name = "lblOverallPercent";
			this.lblOverallPercent.Size = new System.Drawing.Size(40, 24);
			this.lblOverallPercent.TabIndex = 7;
			this.lblOverallPercent.Text = "0%";
			this.lblOverallPercent.TextAlign = System.Drawing.ContentAlignment.BottomRight;
			// 
			// prgOverall
			// 
			this.prgOverall.Location = new System.Drawing.Point(16, 108);
			this.prgOverall.Name = "prgOverall";
			this.prgOverall.Size = new System.Drawing.Size(508, 16);
			this.prgOverall.TabIndex = 2;
			// 
			// label3
			// 
			this.label3.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
			this.label3.Location = new System.Drawing.Point(12, 84);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(92, 23);
			this.label3.TabIndex = 6;
			this.label3.Text = "Overall Progress:";
			this.label3.TextAlign = System.Drawing.ContentAlignment.BottomRight;
			// 
			// prgCurrent
			// 
			this.prgCurrent.Location = new System.Drawing.Point(16, 48);
			this.prgCurrent.Name = "prgCurrent";
			this.prgCurrent.Size = new System.Drawing.Size(508, 16);
			this.prgCurrent.TabIndex = 0;
			// 
			// lblCurrentFile
			// 
			this.lblCurrentFile.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
			this.lblCurrentFile.Location = new System.Drawing.Point(84, 24);
			this.lblCurrentFile.Name = "lblCurrentFile";
			this.lblCurrentFile.Size = new System.Drawing.Size(400, 23);
			this.lblCurrentFile.TabIndex = 3;
			this.lblCurrentFile.TextAlign = System.Drawing.ContentAlignment.BottomLeft;
			// 
			// label1
			// 
			this.label1.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
			this.label1.Location = new System.Drawing.Point(16, 24);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(68, 23);
			this.label1.TabIndex = 1;
			this.label1.Text = "Current File:";
			this.label1.TextAlign = System.Drawing.ContentAlignment.BottomRight;
			// 
			// lblCurrentComplete
			// 
			this.lblCurrentComplete.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
			this.lblCurrentComplete.Location = new System.Drawing.Point(368, 64);
			this.lblCurrentComplete.Name = "lblCurrentComplete";
			this.lblCurrentComplete.Size = new System.Drawing.Size(152, 23);
			this.lblCurrentComplete.TabIndex = 4;
			this.lblCurrentComplete.Text = "0/0";
			this.lblCurrentComplete.TextAlign = System.Drawing.ContentAlignment.TopRight;
			// 
			// lblOverallComplete
			// 
			this.lblOverallComplete.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
			this.lblOverallComplete.Location = new System.Drawing.Point(368, 124);
			this.lblOverallComplete.Name = "lblOverallComplete";
			this.lblOverallComplete.Size = new System.Drawing.Size(152, 23);
			this.lblOverallComplete.TabIndex = 5;
			this.lblOverallComplete.Text = "0/0";
			this.lblOverallComplete.TextAlign = System.Drawing.ContentAlignment.TopRight;
			// 
			// lblCurrentPercent
			// 
			this.lblCurrentPercent.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
			this.lblCurrentPercent.Location = new System.Drawing.Point(484, 24);
			this.lblCurrentPercent.Name = "lblCurrentPercent";
			this.lblCurrentPercent.Size = new System.Drawing.Size(40, 24);
			this.lblCurrentPercent.TabIndex = 3;
			this.lblCurrentPercent.Text = "0%";
			this.lblCurrentPercent.TextAlign = System.Drawing.ContentAlignment.BottomRight;
			// 
			// label4
			// 
			this.label4.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
			this.label4.Location = new System.Drawing.Point(8, 148);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(92, 20);
			this.label4.TabIndex = 8;
			this.label4.Text = "Downloading To:";
			this.label4.TextAlign = System.Drawing.ContentAlignment.BottomRight;
			// 
			// btnCancel
			// 
			this.btnCancel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.btnCancel.FlatStyle = System.Windows.Forms.FlatStyle.System;
			this.btnCancel.Location = new System.Drawing.Point(472, 198);
			this.btnCancel.Name = "btnCancel";
			this.btnCancel.Size = new System.Drawing.Size(75, 28);
			this.btnCancel.TabIndex = 1;
			this.btnCancel.Text = "&Cancel";
			this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
			// 
			// btnPause
			// 
			this.btnPause.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.btnPause.FlatStyle = System.Windows.Forms.FlatStyle.System;
			this.btnPause.Location = new System.Drawing.Point(392, 198);
			this.btnPause.Name = "btnPause";
			this.btnPause.Size = new System.Drawing.Size(75, 28);
			this.btnPause.TabIndex = 2;
			this.btnPause.Text = "&Pause";
			this.btnPause.Click += new System.EventHandler(this.btnPause_Click);
			// 
			// label2
			// 
			this.label2.Font = new System.Drawing.Font("Tahoma", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
			this.label2.Location = new System.Drawing.Point(60, 196);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(288, 23);
			this.label2.TabIndex = 3;
			this.label2.Text = "East Point Systems File Download Utility";
			// 
			// FileDownloaderForm
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(556, 232);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.btnPause);
			this.Controls.Add(this.btnCancel);
			this.Controls.Add(this.groupBox1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.MaximizeBox = false;
			this.Name = "FileDownloaderForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "File Downloader";
			this.Load += new System.EventHandler(this.FileDownloaderForm_Load);
			this.groupBox1.ResumeLayout(false);
			this.ResumeLayout(false);

		}
		#endregion

		public DownloadStatus DownloadStatus
		{
			get
			{
				return this.status;
			}
		}
		private void FileDownloaderForm_Load(object sender, System.EventArgs e)
		{
			//Queuing a thread into the thread pool is faster than instansiating a new one
			System.Threading.ThreadPool.QueueUserWorkItem(new System.Threading.WaitCallback(DoStartDownload));
			Application.DoEvents();
		}
		
		private delegate void CompletedDelegate();

		private void MarshalDownloadComplete()
		{
			if(this.totalSize == this.completedSize)
			{
				this.status = DownloadStatus.Completed;
				this.btnPause.Visible = false;
				this.btnCancel.Text = "&Close";
				canceled = true; //flag close button click event
				if(!unattended)
				{
					MessageBox.Show(this, "Download Complete.", "File Downloader", MessageBoxButtons.OK, MessageBoxIcon.Information);
				}
				else
				{
					this.Close();
				}
			}
		}
		//worker ThreadStart delegate...
		private void DoStartDownload(object state)
		{
			try
			{
				prgOverall.Maximum = 0;
				sizes = new long[urls.Count];
				int i = 0;
				foreach(DownloadURL url in urls)
				{
					bool progressKnown = false;
					sizes[i] = DownloadData.GetFileSize(url.URL, out progressKnown);
					if(!progressKnown)
						throw new Exception("Total size unknown for file: " + url.URL);

					this.prgOverall.Maximum += (int)sizes[i];
					this.totalSize += sizes[i];
					i++;
				}
			
				downloader.ProgressChanged += new DownloadProgressHandler(downloader_ProgressChanged);
				
				if(!this.Visible)
				{
					this.Show();
					Application.DoEvents();
				}

				i = 0;
				long fileSizes = 0;
				foreach(DownloadURL url in urls)
				{
					if(!canceled)
					{
						lastSize = 0;
						this.lblCurrentFile.Text = this.GetURLSizedString(url.URL, MAX_URL_LENGTH);
						
						Uri uri = new Uri(url.URL);
						string fileName = uri.Segments[uri.Segments.Length - 1].ToString();
						this.lblDownlaodingTo.Text = this.GetPathSizedString(
							System.IO.Path.Combine(FileDownloader.DownloaderTempDirectory, fileName), MAX_TEMP_DIR_LENGTH);
						this.prgCurrent.Maximum = (int)sizes[i];
					
						if(url.Destination == string.Empty)
							url.Destination = FileDownloader.DownloaderTempDirectory;
						downloader.Download(url.URL, url.Destination); //System.IO.Path.Combine(TEMP_DIR, 
							//uri.Segments.GetValue(uri.Segments.Length - 1).ToString() ));
						
						if(canceled)
							break;

						fileSizes += sizes[i];
						//if we skipped a file in the begining (already dl'd) make sure the overall value is right
						this.Invoke(new MarshalProgress(MarshaledProgressChanged),
							new object[]{null, new DownloadEventArgs(sizes[i], sizes[i])});
						this.prgOverall.Value = (int)fileSizes; 
						completedSize = fileSizes;			
						i++;
					}
				}
				this.Invoke(new CompletedDelegate(this.MarshalDownloadComplete));
			}
			catch(Exception ex)
			{
				DownloaderExceptionManager.Publish(ex);
			}
		}
		/// <summary>
		/// Prases a URL into elipses if needed (ex: http://download.microsoft.com/.../SomeFile.msi)
		/// </summary>
		/// <param name="url"></param>
		/// <param name="length"></param>
		/// <returns></returns>
		private string GetURLSizedString(string url, int length)
		{
			int whackIndex = url.LastIndexOf("/");
			string keepName = url.Substring(whackIndex, url.Length - whackIndex);
			int resizedLength = length - 3 - keepName.Length;
			
			if(resizedLength > url.Replace(keepName, string.Empty).Length)
				return url; //it's small enough
			
			url = url.Substring(0, resizedLength);
			url += "..." + keepName;
			
			return url;
		}
		private string GetPathSizedString(string path, int length)
		{
			int whackIndex = path.LastIndexOf(@"\");
			string keepName = path.Substring(whackIndex, path.Length - whackIndex);
			int resizedLength = length - 3 - keepName.Length;
			
			if(resizedLength > path.Replace(keepName, string.Empty).Length)
				return path; //it's small enough
			
			path = path.Substring(0, resizedLength);
			path += "..." + keepName;
			
			return path;
		}
		delegate void MarshalProgress(object sender, DownloadEventArgs e);
		private void downloader_ProgressChanged(object sender, DownloadEventArgs e)
		{
			try
			{
				//since the downloader was started on a different thread, it must be invoked
				//back on to the UI thread before we interact with the UI controls
				this.Invoke(new MarshalProgress(this.MarshaledProgressChanged), new object[]{
																								sender, 
																								e});
			}
			catch(Exception ex)
			{
				DownloaderExceptionManager.Publish(ex);
			}
		}
		string lastPercent = string.Empty;
		private void MarshaledProgressChanged(object sender, DownloadEventArgs e)
		{
			try
			{
				this.prgCurrent.Value = (int)e.CurrentFileSize;
				if(e.CurrentFileSize == lastSize) //end of download
				{
					return;
				}
				this.prgOverall.Value += (int)(e.CurrentFileSize - lastSize);
				completedSize += (e.CurrentFileSize - lastSize);
				lastSize = e.CurrentFileSize;

				this.lblCurrentComplete.Text = e.CurrentFileSize + " / " + e.TotalFileSize;
				this.lblOverallComplete.Text = completedSize + " / " + totalSize;

				this.lblCurrentPercent.Text = ((int)((((double)e.CurrentFileSize) / e.TotalFileSize) * 100)).ToString() + "%";
				this.lblOverallPercent.Text = ((int)((((double)completedSize) / totalSize) * 100)).ToString() + "%";

				if(this.lblOverallPercent.Text != lastPercent)
				{
					//if the overall percentage has changed, replace the % portion of the text in the title bar
					int index = Text.IndexOf(" (");
					if(index > -1)
					{
						this.Text = this.Text.Substring(0, index);
					}
			
					this.Text += " (" + this.lblOverallPercent.Text + ")";
					lastPercent = this.lblOverallPercent.Text;
				}

				Application.DoEvents();
			}
			catch(Exception ex)
			{
				DownloaderExceptionManager.Publish(ex);
			}
		}

		private void btnCancel_Click(object sender, System.EventArgs e)
		{
			try
			{
				if(!canceled)
				{
					downloader.Cancel();
					this.status = DownloadStatus.Canceled;
					this.btnCancel.Text = "&Close";
					this.btnPause.Visible = false;
					canceled = true;
				}
				else
				{
					this.Close();
				}
			}
			catch(Exception ex)
			{
				DownloaderExceptionManager.Publish(ex);
			}
		}

		private void btnPause_Click(object sender, System.EventArgs e)
		{
			try
			{
				if(btnPause.Text == "&Pause")
				{
					downloader.Pause();
					btnPause.Text = "&Resume";
				}
				else if(btnPause.Text == "&Resume")
				{
					downloader.Resume();
					btnPause.Text = "&Pause";
				}
			}
			catch(Exception ex)
			{
				DownloaderExceptionManager.Publish(ex);
			}
		}
		sealed class DownloaderExceptionManager
		{
			static FileDownloaderForm downloaderForm = null;
			public static void Initialize(FileDownloaderForm downloaderForm)
			{
				DownloaderExceptionManager.downloaderForm = downloaderForm;
			}
			public static void Publish(Exception ex)
			{
				IWin32Window owner = null;
				if(downloaderForm != null && downloaderForm.Visible)
					owner = downloaderForm;
				MessageBox.Show(downloaderForm, ex.ToString(), "Download Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
				downloaderForm.status = DownloadStatus.Failed;
				downloaderForm.canceled = true;
				downloaderForm.btnCancel.Text = "&Close";
				downloaderForm.btnPause.Visible = false;
			}
		}
	}
	public class DownloadURL
	{
		private string url = string.Empty, dest = string.Empty;
		public DownloadURL(string url)
		{
			this.url = url;
		}
		public DownloadURL(string url, string dest)
		{
			this.url = url;
			this.dest = dest;
		}
		public DownloadURL()
		{
		}
		public string URL
		{
			get
			{
				return url;
			}
		}
		/// <summary>
		/// Gets or sets the destination location of the file (either directory or full path)
		/// If only a directory is supplied, the file name will be parsed from the URL
		/// </summary>
		public string Destination
		{
			get
			{
				if(Path.GetFileName(dest) == string.Empty
					|| Directory.Exists(dest))
				{
					Uri uri = new Uri(url);
					dest = Path.Combine(dest, uri.Segments[uri.Segments.Length - 1].ToString());
				}
				return dest;
			}
			set
			{
				dest = value;
			}
		}
	}
	#region Class DownloadURLCollection

	/// <summary>
	/// Implements a strongly typed collection of <see cref="DownloadURL"/> elements.
	/// </summary>
	/// <remarks><para>
	/// <b>DownloadURLCollection</b> provides an <see cref="ArrayList"/>
	/// that is strongly typed for <see cref="DownloadURL"/> elements.
	/// </para></remarks>

	[Serializable]
	public class DownloadURLCollection: IList, ICloneable 
	{
		#region Private Fields

		private const int _defaultCapacity = 16;

		private DownloadURL[] _array = null;
		private int _count = 0;

		[NonSerialized]
		private int _version = 0;

		#endregion
		#region Private Constructors

		// helper type to identify private ctor
		private enum Tag { Default }

		private DownloadURLCollection(Tag tag) { }

		#endregion
		#region Public Constructors
		#region DownloadURLCollection()

		/// <overloads>
		/// Initializes a new instance of the <see cref="DownloadURLCollection"/> class.
		/// </overloads>
		/// <summary>
		/// Initializes a new instance of the <see cref="DownloadURLCollection"/> class
		/// that is empty and has the default initial capacity.
		/// </summary>
		/// <remarks>Please refer to <see cref="ArrayList()"/> for details.</remarks>

		public DownloadURLCollection() 
		{
			this._array = new DownloadURL[_defaultCapacity];
		}

		#endregion
		#region DownloadURLCollection(Int32)

		/// <summary>
		/// Initializes a new instance of the <see cref="DownloadURLCollection"/> class
		/// that is empty and has the specified initial capacity.
		/// </summary>
		/// <param name="capacity">The number of elements that the new
		/// <see cref="DownloadURLCollection"/> is initially capable of storing.</param>
		/// <exception cref="ArgumentOutOfRangeException">
		/// <paramref name="capacity"/> is less than zero.</exception>
		/// <remarks>Please refer to <see cref="ArrayList(Int32)"/> for details.</remarks>

		public DownloadURLCollection(int capacity) 
		{
			if (capacity < 0)
				throw new ArgumentOutOfRangeException("capacity",
					capacity, "Argument cannot be negative.");

			this._array = new DownloadURL[capacity];
		}

		#endregion
		#region DownloadURLCollection(DownloadURLCollection)

		/// <summary>
		/// Initializes a new instance of the <see cref="DownloadURLCollection"/> class
		/// that contains elements copied from the specified collection and
		/// that has the same initial capacity as the number of elements copied.
		/// </summary>
		/// <param name="collection">The <see cref="DownloadURLCollection"/>
		/// whose elements are copied to the new collection.</param>
		/// <exception cref="ArgumentNullException">
		/// <paramref name="collection"/> is a null reference.</exception>
		/// <remarks>Please refer to <see cref="ArrayList(ICollection)"/> for details.</remarks>

		public DownloadURLCollection(DownloadURLCollection collection) 
		{
			if (collection == null)
				throw new ArgumentNullException("collection");

			this._array = new DownloadURL[collection.Count];
			AddRange(collection);
		}

		#endregion
		#region DownloadURLCollection(DownloadURL[])

		/// <summary>
		/// Initializes a new instance of the <see cref="DownloadURLCollection"/> class
		/// that contains elements copied from the specified <see cref="DownloadURL"/>
		/// array and that has the same initial capacity as the number of elements copied.
		/// </summary>
		/// <param name="array">An <see cref="Array"/> of <see cref="DownloadURL"/>
		/// elements that are copied to the new collection.</param>
		/// <exception cref="ArgumentNullException">
		/// <paramref name="array"/> is a null reference.</exception>
		/// <remarks>Please refer to <see cref="ArrayList(ICollection)"/> for details.</remarks>

		public DownloadURLCollection(DownloadURL[] array) 
		{
			if (array == null)
				throw new ArgumentNullException("array");

			this._array = new DownloadURL[array.Length];
			AddRange(array);
		}

		#endregion
		#endregion
		#region Protected Properties
		#region InnerArray
        
		/// <summary>
		/// Gets the list of elements contained in the <see cref="DownloadURLCollection"/> instance.
		/// </summary>
		/// <value>
		/// A one-dimensional <see cref="Array"/> with zero-based indexing that contains all 
		/// <see cref="DownloadURL"/> elements in the <see cref="DownloadURLCollection"/>.
		/// </value>
		/// <remarks>
		/// Use <b>InnerArray</b> to access the element array of a <see cref="DownloadURLCollection"/>
		/// instance that might be a read-only or synchronized wrapper. This is necessary because
		/// the element array field of wrapper classes is always a null reference.
		/// </remarks>

		protected virtual DownloadURL[] InnerArray 
		{
			get { return this._array; }
		}

		#endregion
		#endregion
		#region Public Properties
		#region Capacity

		/// <summary>
		/// Gets or sets the capacity of the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <value>The number of elements that the
		/// <see cref="DownloadURLCollection"/> can contain.</value>
		/// <exception cref="ArgumentOutOfRangeException">
		/// <b>Capacity</b> is set to a value that is less than <see cref="Count"/>.</exception>
		/// <remarks>Please refer to <see cref="ArrayList.Capacity"/> for details.</remarks>

		public virtual int Capacity 
		{
			get { return this._array.Length; }
			set 
			{
				if (value == this._array.Length) return;

				if (value < this._count)
					throw new ArgumentOutOfRangeException("Capacity",
						value, "Value cannot be less than Count.");

				if (value == 0) 
				{
					this._array = new DownloadURL[_defaultCapacity];
					return;
				}

				DownloadURL[] newArray = new DownloadURL[value];
				Array.Copy(this._array, newArray, this._count);
				this._array = newArray;
			}
		}

		#endregion
		#region Count

		/// <summary>
		/// Gets the number of elements contained in the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <value>
		/// The number of elements contained in the <see cref="DownloadURLCollection"/>.
		/// </value>
		/// <remarks>Please refer to <see cref="ArrayList.Count"/> for details.</remarks>

		public virtual int Count 
		{
			get { return this._count; }
		}

		#endregion
		#region IsFixedSize

		/// <summary>
		/// Gets a value indicating whether the <see cref="DownloadURLCollection"/> has a fixed size.
		/// </summary>
		/// <value><c>true</c> if the <see cref="DownloadURLCollection"/> has a fixed size;
		/// otherwise, <c>false</c>. The default is <c>false</c>.</value>
		/// <remarks>Please refer to <see cref="ArrayList.IsFixedSize"/> for details.</remarks>

		public virtual bool IsFixedSize 
		{
			get { return false; }
		}

		#endregion
		#region IsReadOnly

		/// <summary>
		/// Gets a value indicating whether the <see cref="DownloadURLCollection"/> is read-only.
		/// </summary>
		/// <value><c>true</c> if the <see cref="DownloadURLCollection"/> is read-only;
		/// otherwise, <c>false</c>. The default is <c>false</c>.</value>
		/// <remarks>Please refer to <see cref="ArrayList.IsReadOnly"/> for details.</remarks>

		public virtual bool IsReadOnly 
		{
			get { return false; }
		}

		#endregion
		#region IsSynchronized

		/// <summary>
		/// Gets a value indicating whether access to the <see cref="DownloadURLCollection"/>
		/// is synchronized (thread-safe).
		/// </summary>
		/// <value><c>true</c> if access to the <see cref="DownloadURLCollection"/> is
		/// synchronized (thread-safe); otherwise, <c>false</c>. The default is <c>false</c>.</value>
		/// <remarks>Please refer to <see cref="ArrayList.IsSynchronized"/> for details.</remarks>

		public virtual bool IsSynchronized 
		{
			get { return false; }
		}

		#endregion
		#region IsUnique

		/// <summary>
		/// Gets a value indicating whether the <see cref="DownloadURLCollection"/> 
		/// ensures that all elements are unique.
		/// </summary>
		/// <value>
		/// <c>true</c> if the <see cref="DownloadURLCollection"/> ensures that all 
		/// elements are unique; otherwise, <c>false</c>. The default is <c>false</c>.
		/// </value>
		/// <remarks>
		/// <b>IsUnique</b> returns <c>true</c> exactly if the <see cref="DownloadURLCollection"/>
		/// is exposed through a <see cref="Unique"/> wrapper. 
		/// Please refer to <see cref="Unique"/> for details.
		/// </remarks>

		public virtual bool IsUnique 
		{
			get { return false; }
		}

		#endregion
		#region Item: DownloadURL

		/// <summary>
		/// Gets or sets the <see cref="DownloadURL"/> element at the specified index.
		/// </summary>
		/// <param name="index">The zero-based index of the
		/// <see cref="DownloadURL"/> element to get or set.</param>
		/// <value>
		/// The <see cref="DownloadURL"/> element at the specified <paramref name="index"/>.
		/// </value>
		/// <exception cref="ArgumentOutOfRangeException">
		/// <para><paramref name="index"/> is less than zero.</para>
		/// <para>-or-</para>
		/// <para><paramref name="index"/> is equal to or greater than <see cref="Count"/>.</para>
		/// </exception>
		/// <exception cref="NotSupportedException"><para>
		/// The property is set and the <see cref="DownloadURLCollection"/> is read-only.
		/// </para><para>-or-</para><para>
		/// The property is set, the <b>DownloadURLCollection</b> already contains the
		/// specified element at a different index, and the <b>DownloadURLCollection</b>
		/// ensures that all elements are unique.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.this"/> for details.</remarks>

		public virtual DownloadURL this[int index] 
		{
			get 
			{
				ValidateIndex(index);
				return this._array[index];
			}
			set 
			{
				ValidateIndex(index);
				++this._version;
				this._array[index] = value;
			}
		}

		#endregion
		#region IList.Item: Object

		/// <summary>
		/// Gets or sets the element at the specified index.
		/// </summary>
		/// <param name="index">The zero-based index of the element to get or set.</param>
		/// <value>
		/// The element at the specified <paramref name="index"/>. When the property
		/// is set, this value must be compatible with <see cref="DownloadURL"/>.
		/// </value>
		/// <exception cref="ArgumentOutOfRangeException">
		/// <para><paramref name="index"/> is less than zero.</para>
		/// <para>-or-</para>
		/// <para><paramref name="index"/> is equal to or greater than <see cref="Count"/>.</para>
		/// </exception>
		/// <exception cref="InvalidCastException">The property is set to a value
		/// that is not compatible with <see cref="DownloadURL"/>.</exception>
		/// <exception cref="NotSupportedException"><para>
		/// The property is set and the <see cref="DownloadURLCollection"/> is read-only.
		/// </para><para>-or-</para><para>
		/// The property is set, the <b>DownloadURLCollection</b> already contains the
		/// specified element at a different index, and the <b>DownloadURLCollection</b>
		/// ensures that all elements are unique.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.this"/> for details.</remarks>

		object IList.this[int index] 
		{
			get { return this[index]; }
			set { this[index] = (DownloadURL) value; }
		}

		#endregion
		#region SyncRoot

		/// <summary>
		/// Gets an object that can be used to synchronize
		/// access to the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <value>An object that can be used to synchronize
		/// access to the <see cref="DownloadURLCollection"/>.
		/// </value>
		/// <remarks>Please refer to <see cref="ArrayList.SyncRoot"/> for details.</remarks>

		public virtual object SyncRoot 
		{
			get { return this; }
		}

		#endregion
		#endregion
		#region Public Methods
		#region Add(DownloadURL)

		/// <summary>
		/// Adds a <see cref="DownloadURL"/> to the end of the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <param name="value">The <see cref="DownloadURL"/> object
		/// to be added to the end of the <see cref="DownloadURLCollection"/>.
		/// This argument can be a null reference.
		/// </param>
		/// <returns>The <see cref="DownloadURLCollection"/> index at which the
		/// <paramref name="value"/> has been added.</returns>
		/// <exception cref="NotSupportedException">
		/// <para>The <see cref="DownloadURLCollection"/> is read-only.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> has a fixed size.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> already contains the specified
		/// <paramref name="value"/>, and the <b>DownloadURLCollection</b>
		/// ensures that all elements are unique.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.Add"/> for details.</remarks>

		public virtual int Add(DownloadURL value) 
		{
			if (this._count == this._array.Length)
				EnsureCapacity(this._count + 1);

			++this._version;
			this._array[this._count] = value;
			return this._count++;
		}

		#endregion
		#region IList.Add(Object)

		/// <summary>
		/// Adds an <see cref="Object"/> to the end of the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <param name="value">
		/// The object to be added to the end of the <see cref="DownloadURLCollection"/>.
		/// This argument must be compatible with <see cref="DownloadURL"/>.
		/// This argument can be a null reference.
		/// </param>
		/// <returns>The <see cref="DownloadURLCollection"/> index at which the
		/// <paramref name="value"/> has been added.</returns>
		/// <exception cref="InvalidCastException"><paramref name="value"/>
		/// is not compatible with <see cref="DownloadURL"/>.</exception>
		/// <exception cref="NotSupportedException">
		/// <para>The <see cref="DownloadURLCollection"/> is read-only.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> has a fixed size.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> already contains the specified
		/// <paramref name="value"/>, and the <b>DownloadURLCollection</b>
		/// ensures that all elements are unique.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.Add"/> for details.</remarks>

		int IList.Add(object value) 
		{
			return Add((DownloadURL) value);
		}

		#endregion
		#region AddRange(DownloadURLCollection)

		/// <overloads>
		/// Adds a range of elements to the end of the <see cref="DownloadURLCollection"/>.
		/// </overloads>
		/// <summary>
		/// Adds the elements of another collection to the end of the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <param name="collection">The <see cref="DownloadURLCollection"/> whose elements
		/// should be added to the end of the current collection.</param>
		/// <exception cref="ArgumentNullException">
		/// <paramref name="collection"/> is a null reference.</exception>
		/// <exception cref="NotSupportedException">
		/// <para>The <see cref="DownloadURLCollection"/> is read-only.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> has a fixed size.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> already contains one or more elements
		/// in the specified <paramref name="collection"/>, and the <b>DownloadURLCollection</b>
		/// ensures that all elements are unique.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.AddRange"/> for details.</remarks>

		public virtual void AddRange(DownloadURLCollection collection) 
		{
			if (collection == null)
				throw new ArgumentNullException("collection");

			if (collection.Count == 0) return;
			if (this._count + collection.Count > this._array.Length)
				EnsureCapacity(this._count + collection.Count);

			++this._version;
			Array.Copy(collection.InnerArray, 0,
				this._array, this._count, collection.Count);
			this._count += collection.Count;
		}

		#endregion
		#region AddRange(DownloadURL[])

		/// <summary>
		/// Adds the elements of a <see cref="DownloadURL"/> array
		/// to the end of the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <param name="array">An <see cref="Array"/> of <see cref="DownloadURL"/> elements
		/// that should be added to the end of the <see cref="DownloadURLCollection"/>.</param>
		/// <exception cref="ArgumentNullException">
		/// <paramref name="array"/> is a null reference.</exception>
		/// <exception cref="NotSupportedException">
		/// <para>The <see cref="DownloadURLCollection"/> is read-only.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> has a fixed size.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> already contains one or more elements
		/// in the specified <paramref name="array"/>, and the <b>DownloadURLCollection</b>
		/// ensures that all elements are unique.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.AddRange"/> for details.</remarks>

		public virtual void AddRange(DownloadURL[] array) 
		{
			if (array == null)
				throw new ArgumentNullException("array");

			if (array.Length == 0) return;
			if (this._count + array.Length > this._array.Length)
				EnsureCapacity(this._count + array.Length);

			++this._version;
			Array.Copy(array, 0, this._array, this._count, array.Length);
			this._count += array.Length;
		}

		#endregion
		#region BinarySearch

		/// <summary>
		/// Searches the entire sorted <see cref="DownloadURLCollection"/> for an
		/// <see cref="DownloadURL"/> element using the default comparer
		/// and returns the zero-based index of the element.
		/// </summary>
		/// <param name="value">The <see cref="DownloadURL"/> object
		/// to locate in the <see cref="DownloadURLCollection"/>.
		/// This argument can be a null reference.
		/// </param>
		/// <returns>The zero-based index of <paramref name="value"/> in the sorted
		/// <see cref="DownloadURLCollection"/>, if <paramref name="value"/> is found;
		/// otherwise, a negative number, which is the bitwise complement of the index
		/// of the next element that is larger than <paramref name="value"/> or, if there
		/// is no larger element, the bitwise complement of <see cref="Count"/>.</returns>
		/// <exception cref="InvalidOperationException">
		/// Neither <paramref name="value"/> nor the elements of the <see cref="DownloadURLCollection"/>
		/// implement the <see cref="IComparable"/> interface.</exception>
		/// <remarks>Please refer to <see cref="ArrayList.BinarySearch"/> for details.</remarks>

		public virtual int BinarySearch(DownloadURL value) 
		{
			return Array.BinarySearch(this._array, 0, this._count, value);
		}

		#endregion
		#region Clear

		/// <summary>
		/// Removes all elements from the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <exception cref="NotSupportedException">
		/// <para>The <see cref="DownloadURLCollection"/> is read-only.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> has a fixed size.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.Clear"/> for details.</remarks>

		public virtual void Clear() 
		{
			if (this._count == 0) return;

			++this._version;
			Array.Clear(this._array, 0, this._count);
			this._count = 0;
		}

		#endregion
		#region Clone

		/// <summary>
		/// Creates a shallow copy of the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <returns>A shallow copy of the <see cref="DownloadURLCollection"/>.</returns>
		/// <remarks>Please refer to <see cref="ArrayList.Clone"/> for details.</remarks>

		public virtual object Clone() 
		{
			DownloadURLCollection collection = new DownloadURLCollection(this._count);

			Array.Copy(this._array, 0, collection._array, 0, this._count);
			collection._count = this._count;
			collection._version = this._version;

			return collection;
		}

		#endregion
		#region Contains(DownloadURL)

		/// <summary>
		/// Determines whether the <see cref="DownloadURLCollection"/>
		/// contains the specified <see cref="DownloadURL"/> element.
		/// </summary>
		/// <param name="value">The <see cref="DownloadURL"/> object
		/// to locate in the <see cref="DownloadURLCollection"/>.
		/// This argument can be a null reference.
		/// </param>
		/// <returns><c>true</c> if <paramref name="value"/> is found in the
		/// <see cref="DownloadURLCollection"/>; otherwise, <c>false</c>.</returns>
		/// <remarks>Please refer to <see cref="ArrayList.Contains"/> for details.</remarks>

		public bool Contains(DownloadURL value) 
		{
			return (IndexOf(value) >= 0);
		}

		#endregion
		#region IList.Contains(Object)

		/// <summary>
		/// Determines whether the <see cref="DownloadURLCollection"/> contains the specified element.
		/// </summary>
		/// <param name="value">The object to locate in the <see cref="DownloadURLCollection"/>.
		/// This argument must be compatible with <see cref="DownloadURL"/>.
		/// This argument can be a null reference.
		/// </param>
		/// <returns><c>true</c> if <paramref name="value"/> is found in the
		/// <see cref="DownloadURLCollection"/>; otherwise, <c>false</c>.</returns>
		/// <exception cref="InvalidCastException"><paramref name="value"/>
		/// is not compatible with <see cref="DownloadURL"/>.</exception>
		/// <remarks>Please refer to <see cref="ArrayList.Contains"/> for details.</remarks>

		bool IList.Contains(object value) 
		{
			return Contains((DownloadURL) value);
		}

		#endregion
		#region CopyTo(DownloadURL[])

		/// <overloads>
		/// Copies the <see cref="DownloadURLCollection"/> or a portion of it to a one-dimensional array.
		/// </overloads>
		/// <summary>
		/// Copies the entire <see cref="DownloadURLCollection"/> to a one-dimensional <see cref="Array"/>
		/// of <see cref="DownloadURL"/> elements, starting at the beginning of the target array.
		/// </summary>
		/// <param name="array">The one-dimensional <see cref="Array"/> that is the destination of the
		/// <see cref="DownloadURL"/> elements copied from the <see cref="DownloadURLCollection"/>.
		/// The <b>Array</b> must have zero-based indexing.</param>
		/// <exception cref="ArgumentNullException">
		/// <paramref name="array"/> is a null reference.</exception>
		/// <exception cref="ArgumentException">
		/// The number of elements in the source <see cref="DownloadURLCollection"/> is greater
		/// than the available space in the destination <paramref name="array"/>.</exception>
		/// <remarks>Please refer to <see cref="ArrayList.CopyTo"/> for details.</remarks>

		public virtual void CopyTo(DownloadURL[] array) 
		{
			CheckTargetArray(array, 0);
			Array.Copy(this._array, array, this._count);
		}

		#endregion
		#region CopyTo(DownloadURL[], Int32)

		/// <summary>
		/// Copies the entire <see cref="DownloadURLCollection"/> to a one-dimensional <see cref="Array"/>
		/// of <see cref="DownloadURL"/> elements, starting at the specified index of the target array.
		/// </summary>
		/// <param name="array">The one-dimensional <see cref="Array"/> that is the destination of the
		/// <see cref="DownloadURL"/> elements copied from the <see cref="DownloadURLCollection"/>.
		/// The <b>Array</b> must have zero-based indexing.</param>
		/// <param name="arrayIndex">The zero-based index in <paramref name="array"/>
		/// at which copying begins.</param>
		/// <exception cref="ArgumentNullException">
		/// <paramref name="array"/> is a null reference.</exception>
		/// <exception cref="ArgumentOutOfRangeException">
		/// <paramref name="arrayIndex"/> is less than zero.</exception>
		/// <exception cref="ArgumentException"><para>
		/// <paramref name="arrayIndex"/> is equal to or greater than the length of <paramref name="array"/>.
		/// </para><para>-or-</para><para>
		/// The number of elements in the source <see cref="DownloadURLCollection"/> is greater than the
		/// available space from <paramref name="arrayIndex"/> to the end of the destination
		/// <paramref name="array"/>.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.CopyTo"/> for details.</remarks>

		public virtual void CopyTo(DownloadURL[] array, int arrayIndex) 
		{
			CheckTargetArray(array, arrayIndex);
			Array.Copy(this._array, 0, array, arrayIndex, this._count);
		}

		#endregion
		#region ICollection.CopyTo(Array, Int32)

		/// <summary>
		/// Copies the entire <see cref="DownloadURLCollection"/> to a one-dimensional <see cref="Array"/>,
		/// starting at the specified index of the target array.
		/// </summary>
		/// <param name="array">The one-dimensional <see cref="Array"/> that is the destination of the
		/// <see cref="DownloadURL"/> elements copied from the <see cref="DownloadURLCollection"/>.
		/// The <b>Array</b> must have zero-based indexing.</param>
		/// <param name="arrayIndex">The zero-based index in <paramref name="array"/>
		/// at which copying begins.</param>
		/// <exception cref="ArgumentNullException">
		/// <paramref name="array"/> is a null reference.</exception>
		/// <exception cref="ArgumentOutOfRangeException">
		/// <paramref name="arrayIndex"/> is less than zero.</exception>
		/// <exception cref="ArgumentException"><para>
		/// <paramref name="array"/> is multidimensional.
		/// </para><para>-or-</para><para>
		/// <paramref name="arrayIndex"/> is equal to or greater than the length of <paramref name="array"/>.
		/// </para><para>-or-</para><para>
		/// The number of elements in the source <see cref="DownloadURLCollection"/> is greater than the
		/// available space from <paramref name="arrayIndex"/> to the end of the destination
		/// <paramref name="array"/>.</para></exception>
		/// <exception cref="InvalidCastException">
		/// The <see cref="DownloadURL"/> type cannot be cast automatically
		/// to the type of the destination <paramref name="array"/>.</exception>
		/// <remarks>Please refer to <see cref="ArrayList.CopyTo"/> for details.</remarks>

		void ICollection.CopyTo(Array array, int arrayIndex) 
		{
			CheckTargetArray(array, arrayIndex);
			CopyTo((DownloadURL[]) array, arrayIndex);
		}

		#endregion
		#region GetEnumerator: IDownloadURLEnumerator

		/// <summary>
		/// Returns an <see cref="IDownloadURLEnumerator"/> that can
		/// iterate through the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <returns>An <see cref="IDownloadURLEnumerator"/>
		/// for the entire <see cref="DownloadURLCollection"/>.</returns>
		/// <remarks>Please refer to <see cref="ArrayList.GetEnumerator"/> for details.</remarks>

		public virtual DownloadURLCollection.Enumerator GetEnumerator() 
		{
			return new Enumerator(this);
		}

		#endregion
		#region IEnumerable.GetEnumerator: IEnumerator

		/// <summary>
		/// Returns an <see cref="IEnumerator"/> that can
		/// iterate through the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <returns>An <see cref="IEnumerator"/>
		/// for the entire <see cref="DownloadURLCollection"/>.</returns>
		/// <remarks>Please refer to <see cref="ArrayList.GetEnumerator"/> for details.</remarks>

		IEnumerator IEnumerable.GetEnumerator() 
		{
			return (IEnumerator) GetEnumerator();
		}

		#endregion
		#region IndexOf(DownloadURL)

		/// <summary>
		/// Returns the zero-based index of the first occurrence of the specified
		/// <see cref="DownloadURL"/> in the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <param name="value">The <see cref="DownloadURL"/> object
		/// to locate in the <see cref="DownloadURLCollection"/>.
		/// This argument can be a null reference.
		/// </param>
		/// <returns>
		/// The zero-based index of the first occurrence of <paramref name="value"/>
		/// in the <see cref="DownloadURLCollection"/>, if found; otherwise, -1.
		/// </returns>
		/// <remarks>Please refer to <see cref="ArrayList.IndexOf"/> for details.</remarks>

		public virtual int IndexOf(DownloadURL value) 
		{
			return Array.IndexOf(this._array, value, 0, this._count);
		}

		#endregion
		#region IList.IndexOf(Object)

		/// <summary>
		/// Returns the zero-based index of the first occurrence of the specified
		/// <see cref="Object"/> in the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <param name="value">The object to locate in the <see cref="DownloadURLCollection"/>.
		/// This argument must be compatible with <see cref="DownloadURL"/>.
		/// This argument can be a null reference.
		/// </param>
		/// <returns>
		/// The zero-based index of the first occurrence of <paramref name="value"/>
		/// in the <see cref="DownloadURLCollection"/>, if found; otherwise, -1.
		/// </returns>
		/// <exception cref="InvalidCastException"><paramref name="value"/>
		/// is not compatible with <see cref="DownloadURL"/>.</exception>
		/// <remarks>Please refer to <see cref="ArrayList.IndexOf"/> for details.</remarks>

		int IList.IndexOf(object value) 
		{
			return IndexOf((DownloadURL) value);
		}

		#endregion
		#region Insert(Int32, DownloadURL)

		/// <summary>
		/// Inserts a <see cref="DownloadURL"/> element into the
		/// <see cref="DownloadURLCollection"/> at the specified index.
		/// </summary>
		/// <param name="index">The zero-based index at which <paramref name="value"/>
		/// should be inserted.</param>
		/// <param name="value">The <see cref="DownloadURL"/> object
		/// to insert into the <see cref="DownloadURLCollection"/>.
		/// This argument can be a null reference.
		/// </param>
		/// <exception cref="ArgumentOutOfRangeException">
		/// <para><paramref name="index"/> is less than zero.</para>
		/// <para>-or-</para>
		/// <para><paramref name="index"/> is greater than <see cref="Count"/>.</para>
		/// </exception>
		/// <exception cref="NotSupportedException">
		/// <para>The <see cref="DownloadURLCollection"/> is read-only.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> has a fixed size.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> already contains the specified
		/// <paramref name="value"/>, and the <b>DownloadURLCollection</b>
		/// ensures that all elements are unique.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.Insert"/> for details.</remarks>

		public virtual void Insert(int index, DownloadURL value) 
		{
			if (index < 0)
				throw new ArgumentOutOfRangeException("index",
					index, "Argument cannot be negative.");

			if (index > this._count)
				throw new ArgumentOutOfRangeException("index",
					index, "Argument cannot exceed Count.");

			if (this._count == this._array.Length)
				EnsureCapacity(this._count + 1);

			++this._version;
			if (index < this._count)
				Array.Copy(this._array, index,
					this._array, index + 1, this._count - index);

			this._array[index] = value;
			++this._count;
		}

		#endregion
		#region IList.Insert(Int32, Object)

		/// <summary>
		/// Inserts an element into the <see cref="DownloadURLCollection"/> at the specified index.
		/// </summary>
		/// <param name="index">The zero-based index at which <paramref name="value"/>
		/// should be inserted.</param>
		/// <param name="value">The object to insert into the <see cref="DownloadURLCollection"/>.
		/// This argument must be compatible with <see cref="DownloadURL"/>.
		/// This argument can be a null reference.
		/// </param>
		/// <exception cref="ArgumentOutOfRangeException">
		/// <para><paramref name="index"/> is less than zero.</para>
		/// <para>-or-</para>
		/// <para><paramref name="index"/> is greater than <see cref="Count"/>.</para>
		/// </exception>
		/// <exception cref="InvalidCastException"><paramref name="value"/>
		/// is not compatible with <see cref="DownloadURL"/>.</exception>
		/// <exception cref="NotSupportedException">
		/// <para>The <see cref="DownloadURLCollection"/> is read-only.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> has a fixed size.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> already contains the specified
		/// <paramref name="value"/>, and the <b>DownloadURLCollection</b>
		/// ensures that all elements are unique.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.Insert"/> for details.</remarks>

		void IList.Insert(int index, object value) 
		{
			Insert(index, (DownloadURL) value);
		}

		#endregion
		#region ReadOnly

		/// <summary>
		/// Returns a read-only wrapper for the specified <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <param name="collection">The <see cref="DownloadURLCollection"/> to wrap.</param>
		/// <returns>A read-only wrapper around <paramref name="collection"/>.</returns>
		/// <exception cref="ArgumentNullException">
		/// <paramref name="collection"/> is a null reference.</exception>
		/// <remarks>Please refer to <see cref="ArrayList.ReadOnly"/> for details.</remarks>

		public static DownloadURLCollection ReadOnly(DownloadURLCollection collection) 
		{
			if (collection == null)
				throw new ArgumentNullException("collection");

			return new ReadOnlyList(collection);
		}

		#endregion
		#region Remove(DownloadURL)

		/// <summary>
		/// Removes the first occurrence of the specified <see cref="DownloadURL"/>
		/// from the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <param name="value">The <see cref="DownloadURL"/> object
		/// to remove from the <see cref="DownloadURLCollection"/>.
		/// This argument can be a null reference.
		/// </param>
		/// <exception cref="NotSupportedException">
		/// <para>The <see cref="DownloadURLCollection"/> is read-only.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> has a fixed size.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.Remove"/> for details.</remarks>

		public virtual void Remove(DownloadURL value) 
		{
			int index = IndexOf(value);
			if (index >= 0) RemoveAt(index);
		}

		#endregion
		#region IList.Remove(Object)

		/// <summary>
		/// Removes the first occurrence of the specified <see cref="Object"/>
		/// from the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <param name="value">The object to remove from the <see cref="DownloadURLCollection"/>.
		/// This argument must be compatible with <see cref="DownloadURL"/>.
		/// This argument can be a null reference.
		/// </param>
		/// <exception cref="InvalidCastException"><paramref name="value"/>
		/// is not compatible with <see cref="DownloadURL"/>.</exception>
		/// <exception cref="NotSupportedException">
		/// <para>The <see cref="DownloadURLCollection"/> is read-only.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> has a fixed size.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.Remove"/> for details.</remarks>

		void IList.Remove(object value) 
		{
			Remove((DownloadURL) value);
		}

		#endregion
		#region RemoveAt

		/// <summary>
		/// Removes the element at the specified index of the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <param name="index">The zero-based index of the element to remove.</param>
		/// <exception cref="ArgumentOutOfRangeException">
		/// <para><paramref name="index"/> is less than zero.</para>
		/// <para>-or-</para>
		/// <para><paramref name="index"/> is equal to or greater than <see cref="Count"/>.</para>
		/// </exception>
		/// <exception cref="NotSupportedException">
		/// <para>The <see cref="DownloadURLCollection"/> is read-only.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> has a fixed size.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.RemoveAt"/> for details.</remarks>

		public virtual void RemoveAt(int index) 
		{
			ValidateIndex(index);

			++this._version;
			if (index < --this._count)
				Array.Copy(this._array, index + 1,
					this._array, index, this._count - index);

			this._array[this._count] = null;
		}

		#endregion
		#region RemoveRange

		/// <summary>
		/// Removes the specified range of elements from the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <param name="index">The zero-based starting index of the range
		/// of elements to remove.</param>
		/// <param name="count">The number of elements to remove.</param>
		/// <exception cref="ArgumentException">
		/// <paramref name="index"/> and <paramref name="count"/> do not denote a
		/// valid range of elements in the <see cref="DownloadURLCollection"/>.</exception>
		/// <exception cref="ArgumentOutOfRangeException">
		/// <para><paramref name="index"/> is less than zero.</para>
		/// <para>-or-</para>
		/// <para><paramref name="count"/> is less than zero.</para>
		/// </exception>
		/// <exception cref="NotSupportedException">
		/// <para>The <see cref="DownloadURLCollection"/> is read-only.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> has a fixed size.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.RemoveRange"/> for details.</remarks>

		public virtual void RemoveRange(int index, int count) 
		{
			if (index < 0)
				throw new ArgumentOutOfRangeException("index",
					index, "Argument cannot be negative.");

			if (count < 0)
				throw new ArgumentOutOfRangeException("count",
					count, "Argument cannot be negative.");

			if (index + count > this._count)
				throw new ArgumentException(
					"Arguments denote invalid range of elements.");

			if (count == 0) return;

			++this._version;
			this._count -= count;

			if (index < this._count)
				Array.Copy(this._array, index + count,
					this._array, index, this._count - index);

			Array.Clear(this._array, this._count, count);
		}

		#endregion
		#region Reverse()

		/// <overloads>
		/// Reverses the order of the elements in the 
		/// <see cref="DownloadURLCollection"/> or a portion of it.
		/// </overloads>
		/// <summary>
		/// Reverses the order of the elements in the entire <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <exception cref="NotSupportedException">
		/// The <see cref="DownloadURLCollection"/> is read-only.</exception>
		/// <remarks>Please refer to <see cref="ArrayList.Reverse"/> for details.</remarks>

		public virtual void Reverse() 
		{
			if (this._count <= 1) return;
			++this._version;
			Array.Reverse(this._array, 0, this._count);
		}

		#endregion
		#region Reverse(Int32, Int32)

		/// <summary>
		/// Reverses the order of the elements in the specified range.
		/// </summary>
		/// <param name="index">The zero-based starting index of the range
		/// of elements to reverse.</param>
		/// <param name="count">The number of elements to reverse.</param>
		/// <exception cref="ArgumentException">
		/// <paramref name="index"/> and <paramref name="count"/> do not denote a
		/// valid range of elements in the <see cref="DownloadURLCollection"/>.</exception>
		/// <exception cref="ArgumentOutOfRangeException">
		/// <para><paramref name="index"/> is less than zero.</para>
		/// <para>-or-</para>
		/// <para><paramref name="count"/> is less than zero.</para>
		/// </exception>
		/// <exception cref="NotSupportedException">
		/// The <see cref="DownloadURLCollection"/> is read-only.</exception>
		/// <remarks>Please refer to <see cref="ArrayList.Reverse"/> for details.</remarks>

		public virtual void Reverse(int index, int count) 
		{
			if (index < 0)
				throw new ArgumentOutOfRangeException("index",
					index, "Argument cannot be negative.");

			if (count < 0)
				throw new ArgumentOutOfRangeException("count",
					count, "Argument cannot be negative.");

			if (index + count > this._count)
				throw new ArgumentException(
					"Arguments denote invalid range of elements.");

			if (count <= 1 || this._count <= 1) return;
			++this._version;
			Array.Reverse(this._array, index, count);
		}

		#endregion
		#region Sort()

		/// <overloads>
		/// Sorts the elements in the <see cref="DownloadURLCollection"/> or a portion of it.
		/// </overloads>
		/// <summary>
		/// Sorts the elements in the entire <see cref="DownloadURLCollection"/>
		/// using the <see cref="IComparable"/> implementation of each element.
		/// </summary>
		/// <exception cref="NotSupportedException">
		/// The <see cref="DownloadURLCollection"/> is read-only.</exception>
		/// <remarks>Please refer to <see cref="ArrayList.Sort"/> for details.</remarks>

		public virtual void Sort() 
		{
			if (this._count <= 1) return;
			++this._version;
			Array.Sort(this._array, 0, this._count);
		}

		#endregion
		#region Sort(IComparer)

		/// <summary>
		/// Sorts the elements in the entire <see cref="DownloadURLCollection"/>
		/// using the specified <see cref="IComparer"/> interface.
		/// </summary>
		/// <param name="comparer">
		/// <para>The <see cref="IComparer"/> implementation to use when comparing elements.</para>
		/// <para>-or-</para>
		/// <para>A null reference to use the <see cref="IComparable"/> implementation 
		/// of each element.</para></param>
		/// <exception cref="NotSupportedException">
		/// The <see cref="DownloadURLCollection"/> is read-only.</exception>
		/// <remarks>Please refer to <see cref="ArrayList.Sort"/> for details.</remarks>

		public virtual void Sort(IComparer comparer) 
		{
			if (this._count <= 1) return;
			++this._version;
			Array.Sort(this._array, 0, this._count, comparer);
		}

		#endregion
		#region Sort(Int32, Int32, IComparer)

		/// <summary>
		/// Sorts the elements in the specified range 
		/// using the specified <see cref="IComparer"/> interface.
		/// </summary>
		/// <param name="index">The zero-based starting index of the range
		/// of elements to sort.</param>
		/// <param name="count">The number of elements to sort.</param>
		/// <param name="comparer">
		/// <para>The <see cref="IComparer"/> implementation to use when comparing elements.</para>
		/// <para>-or-</para>
		/// <para>A null reference to use the <see cref="IComparable"/> implementation 
		/// of each element.</para></param>
		/// <exception cref="ArgumentException">
		/// <paramref name="index"/> and <paramref name="count"/> do not denote a
		/// valid range of elements in the <see cref="DownloadURLCollection"/>.</exception>
		/// <exception cref="ArgumentOutOfRangeException">
		/// <para><paramref name="index"/> is less than zero.</para>
		/// <para>-or-</para>
		/// <para><paramref name="count"/> is less than zero.</para>
		/// </exception>
		/// <exception cref="NotSupportedException">
		/// The <see cref="DownloadURLCollection"/> is read-only.</exception>
		/// <remarks>Please refer to <see cref="ArrayList.Sort"/> for details.</remarks>

		public virtual void Sort(int index, int count, IComparer comparer) 
		{
			if (index < 0)
				throw new ArgumentOutOfRangeException("index",
					index, "Argument cannot be negative.");

			if (count < 0)
				throw new ArgumentOutOfRangeException("count",
					count, "Argument cannot be negative.");

			if (index + count > this._count)
				throw new ArgumentException(
					"Arguments denote invalid range of elements.");

			if (count <= 1 || this._count <= 1) return;
			++this._version;
			Array.Sort(this._array, index, count, comparer);
		}

		#endregion
		#region Synchronized

		/// <summary>
		/// Returns a synchronized (thread-safe) wrapper
		/// for the specified <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <param name="collection">The <see cref="DownloadURLCollection"/> to synchronize.</param>
		/// <returns>
		/// A synchronized (thread-safe) wrapper around <paramref name="collection"/>.
		/// </returns>
		/// <exception cref="ArgumentNullException">
		/// <paramref name="collection"/> is a null reference.</exception>
		/// <remarks>Please refer to <see cref="ArrayList.Synchronized"/> for details.</remarks>

		public static DownloadURLCollection Synchronized(DownloadURLCollection collection) 
		{
			if (collection == null)
				throw new ArgumentNullException("collection");

			return new SyncList(collection);
		}

		#endregion
		#region ToArray

		/// <summary>
		/// Copies the elements of the <see cref="DownloadURLCollection"/> to a new
		/// <see cref="Array"/> of <see cref="DownloadURL"/> elements.
		/// </summary>
		/// <returns>A one-dimensional <see cref="Array"/> of <see cref="DownloadURL"/>
		/// elements containing copies of the elements of the <see cref="DownloadURLCollection"/>.</returns>
		/// <remarks>Please refer to <see cref="ArrayList.ToArray"/> for details.</remarks>

		public virtual DownloadURL[] ToArray() 
		{
			DownloadURL[] array = new DownloadURL[this._count];
			Array.Copy(this._array, array, this._count);
			return array;
		}

		#endregion
		#region TrimToSize

		/// <summary>
		/// Sets the capacity to the actual number of elements in the <see cref="DownloadURLCollection"/>.
		/// </summary>
		/// <exception cref="NotSupportedException">
		/// <para>The <see cref="DownloadURLCollection"/> is read-only.</para>
		/// <para>-or-</para>
		/// <para>The <b>DownloadURLCollection</b> has a fixed size.</para></exception>
		/// <remarks>Please refer to <see cref="ArrayList.TrimToSize"/> for details.</remarks>

		public virtual void TrimToSize() 
		{
			Capacity = this._count;
		}

		#endregion
		#region Unique

		/// <summary>
		/// Returns a wrapper for the specified <see cref="DownloadURLCollection"/>
		/// ensuring that all elements are unique.
		/// </summary>
		/// <param name="collection">The <see cref="DownloadURLCollection"/> to wrap.</param>    
		/// <returns>
		/// A wrapper around <paramref name="collection"/> ensuring that all elements are unique.
		/// </returns>
		/// <exception cref="ArgumentException">
		/// <paramref name="collection"/> contains duplicate elements.</exception>
		/// <exception cref="ArgumentNullException">
		/// <paramref name="collection"/> is a null reference.</exception>
		/// <remarks><para>
		/// The <b>Unique</b> wrapper provides a set-like collection by ensuring
		/// that all elements in the <see cref="DownloadURLCollection"/> are unique.
		/// </para><para>
		/// <b>Unique</b> raises an <see cref="ArgumentException"/> if the specified 
		/// <paramref name="collection"/> contains any duplicate elements. The returned
		/// wrapper raises a <see cref="NotSupportedException"/> whenever the user attempts 
		/// to add an element that is already contained in the <b>DownloadURLCollection</b>.
		/// </para><para>
		/// <strong>Note:</strong> The <b>Unique</b> wrapper reflects any changes made
		/// to the underlying <paramref name="collection"/>, including the possible
		/// creation of duplicate elements. The uniqueness of all elements is therefore
		/// no longer assured if the underlying collection is manipulated directly.
		/// </para></remarks>

		public static DownloadURLCollection Unique(DownloadURLCollection collection) 
		{
			if (collection == null)
				throw new ArgumentNullException("collection");

			for (int i = collection.Count - 1; i > 0; i--)
				if (collection.IndexOf(collection[i]) < i)
					throw new ArgumentException("collection",
						"Argument cannot contain duplicate elements.");

			return new UniqueList(collection);
		}

		#endregion
		#endregion
		#region Private Methods
		#region CheckEnumIndex

		private void CheckEnumIndex(int index) 
		{
			if (index < 0 || index >= this._count)
				throw new InvalidOperationException(
					"Enumerator is not on a collection element.");
		}

		#endregion
		#region CheckEnumVersion

		private void CheckEnumVersion(int version) 
		{
			if (version != this._version)
				throw new InvalidOperationException(
					"Enumerator invalidated by modification to collection.");
		}

		#endregion
		#region CheckTargetArray

		private void CheckTargetArray(Array array, int arrayIndex) 
		{
			if (array == null)
				throw new ArgumentNullException("array");
			if (array.Rank > 1)
				throw new ArgumentException(
					"Argument cannot be multidimensional.", "array");

			if (arrayIndex < 0)
				throw new ArgumentOutOfRangeException("arrayIndex",
					arrayIndex, "Argument cannot be negative.");
			if (arrayIndex >= array.Length)
				throw new ArgumentException(
					"Argument must be less than array length.", "arrayIndex");

			if (this._count > array.Length - arrayIndex)
				throw new ArgumentException(
					"Argument section must be large enough for collection.", "array");
		}

		#endregion
		#region EnsureCapacity

		private void EnsureCapacity(int minimum) 
		{
			int newCapacity = (this._array.Length == 0 ?
			_defaultCapacity : this._array.Length * 2);

			if (newCapacity < minimum) newCapacity = minimum;
			Capacity = newCapacity;
		}

		#endregion
		#region ValidateIndex

		private void ValidateIndex(int index) 
		{
			if (index < 0)
				throw new ArgumentOutOfRangeException("index",
					index, "Argument cannot be negative.");

			if (index >= this._count)
				throw new ArgumentOutOfRangeException("index",
					index, "Argument must be less than Count.");
		}

		#endregion
		#endregion
		#region Class Enumerator

		[Serializable]
			public sealed class Enumerator: IEnumerator 
		{
			#region Private Fields

			private readonly DownloadURLCollection _collection;
			private readonly int _version;
			private int _index;

			#endregion
			#region Internal Constructors

			internal Enumerator(DownloadURLCollection collection) 
			{
				this._collection = collection;
				this._version = collection._version;
				this._index = -1;
			}

			#endregion
			#region Public Properties

			public DownloadURL Current 
			{
				get 
				{
					this._collection.CheckEnumIndex(this._index);
					this._collection.CheckEnumVersion(this._version);
					return this._collection[this._index];
				}
			}

			object IEnumerator.Current 
			{
				get { return Current; }
			}

			#endregion
			#region Public Methods

			public bool MoveNext() 
			{
				this._collection.CheckEnumVersion(this._version);
				return (++this._index < this._collection.Count);
			}

			public void Reset() 
			{
				this._collection.CheckEnumVersion(this._version);
				this._index = -1;
			}

			#endregion
		}

		#endregion
		#region Class ReadOnlyList

		[Serializable]
			private sealed class ReadOnlyList: DownloadURLCollection 
		{
			#region Private Fields

			private DownloadURLCollection _collection;

			#endregion
			#region Internal Constructors

			internal ReadOnlyList(DownloadURLCollection collection):
				base(Tag.Default) 
			{
				this._collection = collection;
			}

			#endregion
			#region Protected Properties

			protected override DownloadURL[] InnerArray 
			{
				get { return this._collection.InnerArray; }
			}

			#endregion
			#region Public Properties

			public override int Capacity 
			{
				get { return this._collection.Capacity; }
				set 
				{
					throw new NotSupportedException(
						  "Read-only collections cannot be modified."); }
			}

			public override int Count 
			{
				get { return this._collection.Count; }
			}

			public override bool IsFixedSize 
			{
				get { return true; }
			}

			public override bool IsReadOnly 
			{
				get { return true; }
			}

			public override bool IsSynchronized 
			{
				get { return this._collection.IsSynchronized; }
			}

			public override bool IsUnique 
			{
				get { return this._collection.IsUnique; }
			}

			public override DownloadURL this[int index] 
			{
				get { return this._collection[index]; }
				set 
				{
					throw new NotSupportedException(
						  "Read-only collections cannot be modified."); }
			}

			public override object SyncRoot 
			{
				get { return this._collection.SyncRoot; }
			}

			#endregion
			#region Public Methods

			public override int Add(DownloadURL value) 
			{
				throw new NotSupportedException(
					"Read-only collections cannot be modified.");
			}

			public override void AddRange(DownloadURLCollection collection) 
			{
				throw new NotSupportedException(
					"Read-only collections cannot be modified.");
			}

			public override void AddRange(DownloadURL[] array) 
			{
				throw new NotSupportedException(
					"Read-only collections cannot be modified.");
			}

			public override int BinarySearch(DownloadURL value) 
			{
				return this._collection.BinarySearch(value);
			}

			public override void Clear() 
			{
				throw new NotSupportedException(
					"Read-only collections cannot be modified.");
			}

			public override object Clone() 
			{
				return new ReadOnlyList((DownloadURLCollection) this._collection.Clone());
			}

			public override void CopyTo(DownloadURL[] array) 
			{
				this._collection.CopyTo(array);
			}

			public override void CopyTo(DownloadURL[] array, int arrayIndex) 
			{
				this._collection.CopyTo(array, arrayIndex);
			}

			public override DownloadURLCollection.Enumerator GetEnumerator() 
			{
				return this._collection.GetEnumerator();
			}

			public override int IndexOf(DownloadURL value) 
			{
				return this._collection.IndexOf(value);
			}

			public override void Insert(int index, DownloadURL value) 
			{
				throw new NotSupportedException(
					"Read-only collections cannot be modified.");
			}

			public override void Remove(DownloadURL value) 
			{
				throw new NotSupportedException(
					"Read-only collections cannot be modified.");
			}

			public override void RemoveAt(int index) 
			{
				throw new NotSupportedException(
					"Read-only collections cannot be modified.");
			}

			public override void RemoveRange(int index, int count) 
			{
				throw new NotSupportedException(
					"Read-only collections cannot be modified.");
			}

			public override void Reverse() 
			{
				throw new NotSupportedException(
					"Read-only collections cannot be modified.");
			}

			public override void Reverse(int index, int count) 
			{
				throw new NotSupportedException(
					"Read-only collections cannot be modified.");
			}

			public override void Sort() 
			{
				throw new NotSupportedException(
					"Read-only collections cannot be modified.");
			}

			public override void Sort(IComparer comparer) 
			{
				throw new NotSupportedException(
					"Read-only collections cannot be modified.");
			}

			public override void Sort(int index, int count, IComparer comparer) 
			{
				throw new NotSupportedException(
					"Read-only collections cannot be modified.");
			}

			public override DownloadURL[] ToArray() 
			{
				return this._collection.ToArray();
			}

			public override void TrimToSize() 
			{
				throw new NotSupportedException(
					"Read-only collections cannot be modified.");
			}

			#endregion
		}

		#endregion
		#region Class SyncList

		[Serializable]
			private sealed class SyncList: DownloadURLCollection 
		{
			#region Private Fields

			private DownloadURLCollection _collection;
			private object _root;

			#endregion
			#region Internal Constructors

			internal SyncList(DownloadURLCollection collection):
				base(Tag.Default) 
			{

				this._root = collection.SyncRoot;
				this._collection = collection;
			}

			#endregion
			#region Protected Properties

			protected override DownloadURL[] InnerArray 
			{
				get { lock (this._root) return this._collection.InnerArray; }
			}

			#endregion
			#region Public Properties

			public override int Capacity 
			{
				get { lock (this._root) return this._collection.Capacity; }
				set { lock (this._root) this._collection.Capacity = value; }
			}

			public override int Count 
			{
				get { lock (this._root) return this._collection.Count; }
			}

			public override bool IsFixedSize 
			{
				get { return this._collection.IsFixedSize; }
			}

			public override bool IsReadOnly 
			{
				get { return this._collection.IsReadOnly; }
			}

			public override bool IsSynchronized 
			{
				get { return true; }
			}

			public override bool IsUnique 
			{
				get { return this._collection.IsUnique; }
			}

			public override DownloadURL this[int index] 
			{
				get { lock (this._root) return this._collection[index]; }
				set { lock (this._root) this._collection[index] = value;  }
			}

			public override object SyncRoot 
			{
				get { return this._root; }
			}

			#endregion
			#region Public Methods

			public override int Add(DownloadURL value) 
			{
				lock (this._root) return this._collection.Add(value);
			}

			public override void AddRange(DownloadURLCollection collection) 
			{
				lock (this._root) this._collection.AddRange(collection);
			}

			public override void AddRange(DownloadURL[] array) 
			{
				lock (this._root) this._collection.AddRange(array);
			}

			public override int BinarySearch(DownloadURL value) 
			{
				lock (this._root) return this._collection.BinarySearch(value);
			}

			public override void Clear() 
			{
				lock (this._root) this._collection.Clear();
			}

			public override object Clone() 
			{
				lock (this._root)
					return new SyncList((DownloadURLCollection) this._collection.Clone());
			}

			public override void CopyTo(DownloadURL[] array) 
			{
				lock (this._root) this._collection.CopyTo(array);
			}

			public override void CopyTo(DownloadURL[] array, int arrayIndex) 
			{
				lock (this._root) this._collection.CopyTo(array, arrayIndex);
			}

			public override DownloadURLCollection.Enumerator GetEnumerator() 
			{
				lock (this._root) return this._collection.GetEnumerator();
			}

			public override int IndexOf(DownloadURL value) 
			{
				lock (this._root) return this._collection.IndexOf(value);
			}

			public override void Insert(int index, DownloadURL value) 
			{
				lock (this._root) this._collection.Insert(index, value);
			}

			public override void Remove(DownloadURL value) 
			{
				lock (this._root) this._collection.Remove(value);
			}

			public override void RemoveAt(int index) 
			{
				lock (this._root) this._collection.RemoveAt(index);
			}

			public override void RemoveRange(int index, int count) 
			{
				lock (this._root) this._collection.RemoveRange(index, count);
			}

			public override void Reverse() 
			{
				lock (this._root) this._collection.Reverse();
			}

			public override void Reverse(int index, int count) 
			{
				lock (this._root) this._collection.Reverse(index, count);
			}

			public override void Sort() 
			{
				lock (this._root) this._collection.Sort();
			}

			public override void Sort(IComparer comparer) 
			{
				lock (this._root) this._collection.Sort(comparer);
			}

			public override void Sort(int index, int count, IComparer comparer) 
			{
				lock (this._root) this._collection.Sort(index, count, comparer);
			}

			public override DownloadURL[] ToArray() 
			{
				lock (this._root) return this._collection.ToArray();
			}

			public override void TrimToSize() 
			{
				lock (this._root) this._collection.TrimToSize();
			}

			#endregion
		}

		#endregion
		#region Class UniqueList

		[Serializable]
			private sealed class UniqueList: DownloadURLCollection 
		{
			#region Private Fields

			private DownloadURLCollection _collection;

			#endregion
			#region Internal Constructors

			internal UniqueList(DownloadURLCollection collection):
				base(Tag.Default) 
			{
				this._collection = collection;
			}

			#endregion
			#region Protected Properties

			protected override DownloadURL[] InnerArray 
			{
				get { return this._collection.InnerArray; }
			}

			#endregion
			#region Public Properties

			public override int Capacity 
			{
				get { return this._collection.Capacity; }
				set { this._collection.Capacity = value; }
			}

			public override int Count 
			{
				get { return this._collection.Count; }
			}

			public override bool IsFixedSize 
			{
				get { return this._collection.IsFixedSize; }
			}

			public override bool IsReadOnly 
			{
				get { return this._collection.IsReadOnly; }
			}

			public override bool IsSynchronized 
			{
				get { return this._collection.IsSynchronized; }
			}

			public override bool IsUnique 
			{
				get { return true; }
			}

			public override DownloadURL this[int index] 
			{
				get { return this._collection[index]; }
				set 
				{
					CheckUnique(index, value);
					this._collection[index] = value;
				}
			}

			public override object SyncRoot 
			{
				get { return this._collection.SyncRoot; }
			}

			#endregion
			#region Public Methods

			public override int Add(DownloadURL value) 
			{
				CheckUnique(value);
				return this._collection.Add(value);
			}

			public override void AddRange(DownloadURLCollection collection) 
			{
				foreach (DownloadURL value in collection)
					CheckUnique(value);
            
				this._collection.AddRange(collection);
			}

			public override void AddRange(DownloadURL[] array) 
			{
				foreach (DownloadURL value in array)
					CheckUnique(value);
            
				this._collection.AddRange(array);
			}

			public override int BinarySearch(DownloadURL value) 
			{
				return this._collection.BinarySearch(value);
			}

			public override void Clear() 
			{
				this._collection.Clear();
			}

			public override object Clone() 
			{
				return new UniqueList((DownloadURLCollection) this._collection.Clone());
			}

			public override void CopyTo(DownloadURL[] array) 
			{
				this._collection.CopyTo(array);
			}

			public override void CopyTo(DownloadURL[] array, int arrayIndex) 
			{
				this._collection.CopyTo(array, arrayIndex);
			}

			public override DownloadURLCollection.Enumerator GetEnumerator() 
			{
				return this._collection.GetEnumerator();
			}

			public override int IndexOf(DownloadURL value) 
			{
				return this._collection.IndexOf(value);
			}

			public override void Insert(int index, DownloadURL value) 
			{
				CheckUnique(value);
				this._collection.Insert(index, value);
			}

			public override void Remove(DownloadURL value) 
			{
				this._collection.Remove(value);
			}

			public override void RemoveAt(int index) 
			{
				this._collection.RemoveAt(index);
			}

			public override void RemoveRange(int index, int count) 
			{
				this._collection.RemoveRange(index, count);
			}

			public override void Reverse() 
			{
				this._collection.Reverse();
			}

			public override void Reverse(int index, int count) 
			{
				this._collection.Reverse(index, count);
			}

			public override void Sort() 
			{
				this._collection.Sort();
			}

			public override void Sort(IComparer comparer) 
			{
				this._collection.Sort(comparer);
			}

			public override void Sort(int index, int count, IComparer comparer) 
			{
				this._collection.Sort(index, count, comparer);
			}

			public override DownloadURL[] ToArray() 
			{
				return this._collection.ToArray();
			}

			public override void TrimToSize() 
			{
				this._collection.TrimToSize();
			}

			#endregion
			#region Private Methods

			private void CheckUnique(DownloadURL value) 
			{
				if (IndexOf(value) >= 0)
					throw new NotSupportedException(
						"Unique collections cannot contain duplicate elements.");
			}

			private void CheckUnique(int index, DownloadURL value) 
			{
				int existing = IndexOf(value);
				if (existing >= 0 && existing != index)
					throw new NotSupportedException(
						"Unique collections cannot contain duplicate elements.");
			}

			#endregion
		}

		#endregion
	}

	#endregion
}
