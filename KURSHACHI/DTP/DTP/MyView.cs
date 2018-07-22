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
        public static void config()
        {
            Console.WriteLine("-CONFIGS-");
            Console.WriteLine("Вероятность короткой задачи - " + Config.R);
            Console.WriteLine("Время максимальной задачи - " + Config.M);
            Console.WriteLine("Ввант за 1 такт - " + Config.Q);
            Console.WriteLine("Кол-во задач - " + Config.C);
            Console.WriteLine("Кол-во процс - " + Config.N);
            Console.WriteLine("Время для задачи - " + Config.L);
            Console.WriteLine();
        }

        public static void show(Info info)
        {
            Console.WriteLine("  Всего тактов = " + info.countTackts);
            Console.WriteLine("  Кол-во длинных = " + info.countLong);
            Console.WriteLine("  Кол-во коротких = " + info.countShort);
            Console.WriteLine("  Кол-во пустых = " + info.countEmpty);
            Console.WriteLine("  Среднее время = " + info.timeAVG);
            Console.WriteLine("  Средняя нагрузка = " + info.loadAVG);
            Console.WriteLine();
        }

        public static void showSPT(Computer comp)
        {
            Console.WriteLine("___SPT___");
            MyView.showTask(comp.tasks);
            MyView.showCPUs(comp.CPUs);
        }

        public static void showRR(Computer comp)
        {
            Console.WriteLine("___RR___");
            MyView.showTask(comp.tasks);
            MyView.showCPUs(comp.CPUs);
        }

        public static void showMAK(Computer comp)
        {
            Console.WriteLine("___MAK___");
            MyView.showTask(comp.tasks);
            MyView.showCPUs(comp.CPUs);
        }

        public static void showLPT(Computer comp)
        {
            Console.WriteLine("___LPT___");
            MyView.showTask(comp.tasks);
            MyView.showCPUs(comp.CPUs);
        }

        public static void showTask(List<Task> tasks)
        {
            Console.WriteLine("TASKS:");
            foreach (Task t in tasks)
                Console.Write(t.name + " - " + t.tmp + " | ");
            Console.WriteLine();
            Console.WriteLine();
        }

        public static void showCPUs(List<CPU> CPUs)
        {
            Console.WriteLine("CPUs:");
            foreach (CPU c in CPUs)
            {
                Console.Write(c.name + " = ");
                foreach (Task p in c.process)
                    Console.Write(p.name + " | ");
                Console.WriteLine();
            }
            Console.WriteLine();
        }

        public static void getData(ListBox box, Info info)
        {
            box.Items.Add("Всего тактов = " + info.countTackts + "\n");
            box.Items.Add("Кол-во длинных = " + info.countLong + "\n");
            box.Items.Add("Кол-во коротких = " + info.countShort + "\n");
            box.Items.Add("Кол-во пустых = " + info.countEmpty + "\n");
            box.Items.Add("Среднее время = " + info.timeAVG + "\n");
            box.Items.Add("Средняя нагрузка = " + info.loadAVG + "\n");
        }

        public static void getTasks(ListBox box, List<Task> tasks)
        {
            foreach (Task t in tasks)
                box.Items.Add((t.name + " - " + t.tmp + " | ") + "\n");
        }

        public static void getCPUs(ListBox box, List<CPU> CPUs)
        {
            String res = "";

            foreach (CPU c in CPUs)
            {
                res = (c.name + " = ");
                foreach (Task t in c.process)
                   res += (t.name + " | ");
                box.Items.Add(res);
            }
        }
    }
}
