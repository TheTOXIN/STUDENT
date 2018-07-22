using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Windows.Forms;

namespace DTP
{
    public class MyView
    {
        public static void getData(ListBox box, Info info)
        {
            box.Items.Add("Теоритическое заначение производительности: " + info.t_perfomence);
            box.Items.Add("Опытное значение производительности: " + info.e_perfomence);
            box.Items.Add("Кол-во коллизий: " + info.collision);
            box.Items.Add("Общее время передачи кадров: " + info.main_time);
            box.Items.Add("Вемя передачи одного кадра:" + info.pocket_time);
        }

        public static void getTasks(ListBox box, List<double> p) 
        {
            for (int i = 0; i < p.Count; i++)
            {
                box.Items.Add(i + " - " + (p[i].ToString()).Substring(0, 4));
            }
        }
    }
}
