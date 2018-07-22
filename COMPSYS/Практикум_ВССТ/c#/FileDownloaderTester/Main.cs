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
                /*urls.Add(new DownloadURL("http://users.peswe.com/driver/pictur1.files/image001.jpg",
					@"C:\work\file1.jpg"));
                urls.Add(new DownloadURL("http://users.peswe.com/driver/zsnesw.rar",
					@"C:\work\file2.rar"));*/
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
