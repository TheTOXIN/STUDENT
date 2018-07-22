using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace Lab1_1
{
	public partial class MainForm : Form
	{
		public MainForm()
		{
			InitializeComponent();
		}
		
		void Button1Click(object sender, EventArgs e)
		{
			Random r = new Random();
			Queue<int> q = new Queue<int>();
			int chance = Convert.ToInt32(chanceNUD.Value);
			int maxLength = Convert.ToInt32(maxLengthNUD.Value);
			int shortValue = Convert.ToInt32(shortNUD.Value);
			int countTackts = 0;
			int countShortValues = 0;
			int countEmptyValues = 0;
			int timeToShortValues = 0;
			for(int i = Convert.ToInt32(countNUD.Value); i > 0; --i)
			{
				if(r.Next(100) > chance)
					q.Enqueue(r.Next(1, maxLength));
				else
					q.Enqueue(0);
			}
			
			resultBox.Items.Clear();
			foreach(int i in q)
				resultBox.Items.Add(i);
			
			int[] ar = q.ToArray();
			Array.Sort(ar);
			
			for(int i = 0; i < ar.Length; ++i)
			{
				if(ar[i] != 0)
				{
					++countTackts;
					if(ar[i] <= shortValue)
					{
						++countShortValues;
						timeToShortValues += ar[i];
						ar[i] = 0;
					}
					else
					{
						while(ar[i] >= shortValue)
						{
							++countTackts;
							ar[i] -= shortValue;
						}
					}
				}
				else
					++countEmptyValues;
			}
			
			infoBox.Items.Clear();
			infoBox.Items.Add("Короткие заявки " + countShortValues);
			infoBox.Items.Add("Пустые заявки " + countEmptyValues);
			infoBox.Items.Add("Выполенные такты " + countTackts);
			infoBox.Items.Add("Время на короткие заявки " + countShortValues * Convert.ToInt32(timeNUD.Value));
			infoBox.Items.Add("Сред. время ожидания короткий заявки " +  countShortValues / (Convert.ToDouble(countNUD.Value) - countEmptyValues));
		}
		
		void Button2Click(object sender, EventArgs e)
		{
			Random r = new Random();
			Queue<int> q = new Queue<int>();
			int chance = Convert.ToInt32(chanceNUD.Value);
			int maxLength = Convert.ToInt32(maxLengthNUD.Value);
			int shortValue = Convert.ToInt32(shortNUD.Value);
			int countTackts = 0;
			int countShortValues = 0;
			int countEmptyValues = 0;
			int timeToShortValues = 0;
			int countLongValues = 0;
			int i = 0;
			for(i = Convert.ToInt32(countNUD.Value); i > 0; --i)
			{
				if(r.Next(100) > chance)
					q.Enqueue(r.Next(1, maxLength));
				else
					q.Enqueue(0);
			}
			
			resultBox.Items.Clear();
			foreach(int v in q)
			{
				resultBox.Items.Add(v);
				if(v == 0)
					++countEmptyValues;
				else
				{
					if(v <= shortValue)
						++countShortValues;
				}
			}
			
			int[] ar = q.ToArray();
			
			bool f = false;
			
			do
			{
				f = false;
				for(i = 0; i < ar.Length; ++i)
				{
					if(ar[i] != 0)
					{
						++countTackts;
						f = true;
						if(ar[i] <= shortValue)
							ar[i] = 0;
						else
							ar[i] -= shortValue;
					}
				}
			}
			while(f);
			
			infoBox.Items.Clear();
			infoBox.Items.Add("Короткие заявки " + countShortValues);
			infoBox.Items.Add("Пустые заявки " + countEmptyValues);
			infoBox.Items.Add("Выполенные такты " + countTackts);
			infoBox.Items.Add("Время на короткие заявки " + countShortValues * Convert.ToInt32(timeNUD.Value));
			infoBox.Items.Add("Сред. время ожидания короткий заявки " +  countShortValues / (Convert.ToDouble(countNUD.Value) - countEmptyValues));
		}
	}
}
