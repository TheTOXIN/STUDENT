/*
 * Created by SharpDevelop.
 * User: User
 * Date: 19.02.2018
 * Time: 15:35
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace Lab1_1
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.button1 = new System.Windows.Forms.Button();
			this.chanceNUD = new System.Windows.Forms.NumericUpDown();
			this.label1 = new System.Windows.Forms.Label();
			this.countNUD = new System.Windows.Forms.NumericUpDown();
			this.label2 = new System.Windows.Forms.Label();
			this.maxLengthNUD = new System.Windows.Forms.NumericUpDown();
			this.label3 = new System.Windows.Forms.Label();
			this.shortNUD = new System.Windows.Forms.NumericUpDown();
			this.label4 = new System.Windows.Forms.Label();
			this.resultBox = new System.Windows.Forms.ListBox();
			this.infoBox = new System.Windows.Forms.ListBox();
			this.label5 = new System.Windows.Forms.Label();
			this.timeNUD = new System.Windows.Forms.NumericUpDown();
			this.button2 = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.chanceNUD)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.countNUD)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.maxLengthNUD)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.shortNUD)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.timeNUD)).BeginInit();
			this.SuspendLayout();
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(12, 147);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(100, 23);
			this.button1.TabIndex = 0;
			this.button1.Text = "Выполнить SPT";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.Button1Click);
			// 
			// chanceNUD
			// 
			this.chanceNUD.Location = new System.Drawing.Point(152, 12);
			this.chanceNUD.Name = "chanceNUD";
			this.chanceNUD.Size = new System.Drawing.Size(120, 20);
			this.chanceNUD.TabIndex = 1;
			this.chanceNUD.Value = new decimal(new int[] {
									50,
									0,
									0,
									0});
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(12, 14);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(100, 23);
			this.label1.TabIndex = 2;
			this.label1.Text = "Вероятность";
			// 
			// countNUD
			// 
			this.countNUD.Location = new System.Drawing.Point(152, 38);
			this.countNUD.Name = "countNUD";
			this.countNUD.Size = new System.Drawing.Size(120, 20);
			this.countNUD.TabIndex = 3;
			this.countNUD.Value = new decimal(new int[] {
									20,
									0,
									0,
									0});
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(12, 40);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(100, 23);
			this.label2.TabIndex = 4;
			this.label2.Text = "Кол-во заявок";
			// 
			// maxLengthNUD
			// 
			this.maxLengthNUD.Location = new System.Drawing.Point(152, 64);
			this.maxLengthNUD.Name = "maxLengthNUD";
			this.maxLengthNUD.Size = new System.Drawing.Size(120, 20);
			this.maxLengthNUD.TabIndex = 5;
			this.maxLengthNUD.Value = new decimal(new int[] {
									20,
									0,
									0,
									0});
			// 
			// label3
			// 
			this.label3.Location = new System.Drawing.Point(12, 66);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(100, 23);
			this.label3.TabIndex = 6;
			this.label3.Text = "Макс. длина";
			// 
			// shortNUD
			// 
			this.shortNUD.Location = new System.Drawing.Point(152, 90);
			this.shortNUD.Name = "shortNUD";
			this.shortNUD.Size = new System.Drawing.Size(120, 20);
			this.shortNUD.TabIndex = 7;
			this.shortNUD.Value = new decimal(new int[] {
									3,
									0,
									0,
									0});
			// 
			// label4
			// 
			this.label4.Location = new System.Drawing.Point(12, 92);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(100, 23);
			this.label4.TabIndex = 8;
			this.label4.Text = "Короткая заявка";
			// 
			// resultBox
			// 
			this.resultBox.FormattingEnabled = true;
			this.resultBox.Location = new System.Drawing.Point(12, 176);
			this.resultBox.Name = "resultBox";
			this.resultBox.Size = new System.Drawing.Size(120, 108);
			this.resultBox.TabIndex = 9;
			// 
			// infoBox
			// 
			this.infoBox.FormattingEnabled = true;
			this.infoBox.Location = new System.Drawing.Point(152, 176);
			this.infoBox.Name = "infoBox";
			this.infoBox.Size = new System.Drawing.Size(251, 108);
			this.infoBox.TabIndex = 10;
			// 
			// label5
			// 
			this.label5.Location = new System.Drawing.Point(12, 120);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(100, 23);
			this.label5.TabIndex = 11;
			this.label5.Text = "Время";
			// 
			// timeNUD
			// 
			this.timeNUD.Location = new System.Drawing.Point(152, 118);
			this.timeNUD.Name = "timeNUD";
			this.timeNUD.Size = new System.Drawing.Size(120, 20);
			this.timeNUD.TabIndex = 12;
			this.timeNUD.Value = new decimal(new int[] {
									5,
									0,
									0,
									0});
			// 
			// button2
			// 
			this.button2.Location = new System.Drawing.Point(152, 147);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(94, 23);
			this.button2.TabIndex = 13;
			this.button2.Text = "Выполнить RR";
			this.button2.UseVisualStyleBackColor = true;
			this.button2.Click += new System.EventHandler(this.Button2Click);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(415, 291);
			this.Controls.Add(this.button2);
			this.Controls.Add(this.timeNUD);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.infoBox);
			this.Controls.Add(this.resultBox);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.shortNUD);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.maxLengthNUD);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.countNUD);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.chanceNUD);
			this.Controls.Add(this.button1);
			this.Name = "MainForm";
			this.Text = "Lab1_1";
			((System.ComponentModel.ISupportInitialize)(this.chanceNUD)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.countNUD)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.maxLengthNUD)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.shortNUD)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.timeNUD)).EndInit();
			this.ResumeLayout(false);
		}
		private System.Windows.Forms.Button button2;
		private System.Windows.Forms.NumericUpDown timeNUD;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.ListBox infoBox;
		private System.Windows.Forms.ListBox resultBox;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.NumericUpDown shortNUD;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.NumericUpDown maxLengthNUD;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.NumericUpDown countNUD;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.NumericUpDown chanceNUD;
		private System.Windows.Forms.Button button1;
	}
}
