using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DTP
{
    public class VIew
    {
        public static void config()
        {
            Console.WriteLine("-CONFIGS-");
            Console.WriteLine("Вероятность короткой задачи - " + Config.R);
            Console.WriteLine("Время максимальной задачи - " + Config.M);
            Console.WriteLine("Квант за 1 такт - " + Config.Q);
            Console.WriteLine("Кол-во задач - " + Config.С);
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
            Console.WriteLine("  Среднее время коротких = " + info.timeShort);
            Console.WriteLine("  Средняя нагрузка = " + info.loadAVG);
            if (info.hol != null && !info.hol.Equals(""))
                Console.WriteLine(info.hol);
            Console.WriteLine();
        }

        public static void showSPT(Computer comp)
        {
            Console.WriteLine("___SPT___");
            VIew.showTask(comp.tasks);
            VIew.showCPUs(comp.CPUs);
        }

        public static void showRR(Computer comp)
        {
            Console.WriteLine("___RR___");
            VIew.showTask(comp.tasks);
            VIew.showCPUs(comp.CPUs);
        }

        public static void showMAK(Computer comp)
        {
            Console.WriteLine("___MAK___");
            VIew.showTask(comp.tasks);
            VIew.showCPUs(comp.CPUs);
        }

        public static void showLPT(Computer comp)
        {
            Console.WriteLine("___LPT___");
            VIew.showTask(comp.tasks);
            VIew.showCPUs(comp.CPUs);
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
    }
}
