using System;
using System.Windows.Forms;

namespace FileDownloaderTester
{
	/// <summary>
	/// Summary description for ExceptionManager.
	/// </summary>
	public class ExceptionManager
	{
		public static void Publish(Exception ex)
		{
			MessageBox.Show(ex.ToString(), "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
		}
	}
}
