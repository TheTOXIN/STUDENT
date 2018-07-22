using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

using EPS.Libraries.ClientLibrary.HttpUtils;

namespace FileDownloaderTester
{
	/// <summary>
	/// Summary description for Form1.
	/// </summary>
	public class MainClass
	{
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main() 
		{
			try
			{
				//turn on themes in windows >xp
				Application.EnableVisualStyles();
				Application.DoEvents();

				DownloadURLCollection urls = new DownloadURLCollection();
				urls.Add(new DownloadURL("http://www.codeproject.com/cs/internet/CoolDownloader/CoolDownloader_demo.zip",
					@"C:\Temp"));
				urls.Add(new DownloadURL("http://releases.mozilla.org/pub/mozilla.org/firefox/releases/1.5.0.6/win32/en-US/Firefox Setup 1.5.0.6.exe",
					@"C:\Temp\newname.zip"));
				FileDownloaderForm downloader = new FileDownloaderForm(urls);
				downloader.ShowDialog();
			}
			catch(Exception ex)
			{
				ExceptionManager.Publish(ex);
			}
		}
	}
}
