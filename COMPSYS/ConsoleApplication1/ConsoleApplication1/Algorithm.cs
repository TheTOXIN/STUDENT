using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DTP
{
    public class Algorithm
    {
        private Info info = new Info();

        public Info SPT(List<Task> tasks, List<CPU> CPUs) 
        {
            info.clear();

            Task[] ar = tasks.ToArray();
            Array.Sort(ar);

            for (int i = 0; i < ar.Length; i++)
            {
                if (!ar[i].isEmpty())
                {
                    info.countTackts++;
                    if (ar[i].isShort())
                    {
                        info.countShort++;
                        info.timeShort += ar[i].time;
                        ar[i].time = 0;
                        CPUs[0].process.Add(ar[i]);
                    }
                    else
                    {
                        while (!ar[i].isShort())
                        {
                            info.countTackts++;
                            ar[i].time -= Config.Q;
                        }
                    }

                    info.timeShort += ar[i].time;
                    info.timeAVG += (double)ar[i].time;
                    ar[i].isReady = true;
                }
                else
                {
                    info.countEmpty++;
                }
            }

            info.compute();
            return info; 
        }

        public Info RR(List<Task> tasks, List<CPU> CPUs) 
        {
            info.clear();

            Task[] ar = tasks.ToArray();
            Array.Sort(ar);

            for (int i = 0; i < ar.Length; i++)
                if (ar[i].isEmpty())
                    info.countEmpty++;
                else
                    if (ar[i].isShort())
                    {
                        info.countShort++;
                        info.timeShort += ar[i].time;
                    }

            bool f = false;
            do
            {
                f = false;
                for (int i = 0; i < ar.Length; i++)
                {
                    if (!ar[i].isEmpty())
                    {
                        info.countTackts++;
                        f = true;
                        if (ar[i].isShort())
                        {
                            CPUs[0].process.Add(ar[i]);
                            ar[i].time = 0;
                            info.timeShort += ar[i].time;
                        }
                        else
                        {
                            ar[i].time -= Config.Q;
                        }
                        info.timeAVG += (double)ar[i].time;
                    }
                }
            }
            while (f);

            info.compute();
            return info; 
        }

        public Info LPT(List<Task> tasks, List<CPU> CPUs) 
        {
            info.clear();

            tasks.Sort();

            foreach (Task t in tasks)
                if (t.isEmpty())
                    info.countEmpty++;
                else
                    if (t.isShort())
                    {
                        info.countShort++;
                        info.timeShort += t.time;
                    }

            int avg = 0;
            foreach (Task t in tasks)
                avg += t.time;
            avg /= Config.N;
            info.loadAVG = avg;
            avg++;

            bool f = true;
            do
            {
                Task t = null;
                foreach (Task i in tasks)
                    if (i.isEmpty())
                        continue;
                    else
                        t = i;

                if (t == null)
                {
                    f = false;
                    break;
                }

                CPU c = CPUs[0];
                foreach (CPU i in CPUs)
                    if (i.loader < c.loader)
                        c = i;

                c.process.Add(t);
                c.loader += t.time;
                t.time = 0;
                info.countTackts++;

                if (c.isLoad(avg))
                {
                    int raz = c.loader - avg;
                    c.loader -= raz;
                    t.time = raz;
                }
            } while (f);

            info.compute();
            return info; 
        }

        public Info MAK(List<Task> tasks, List<CPU> CPUs) 
        {
            info.clear();

            int avg = 0;
            int sum = 0;
            int max = 0;

            foreach (Task t in tasks)
                if (t.isEmpty())
                    info.countEmpty++;
                else
                    if (t.isShort())
                    {
                        info.countShort++;
                        info.timeShort += t.time;
                    }

            foreach (Task t in tasks)
            {
                sum += t.time;
                if (max <= t.time)
                    max = t.time;
            }

            if (sum % Config.N != 0)
            {
                avg = Math.Max(max, sum / Config.N) + 1;
                info.hol = "   Холостой = TRUE";
            }
            else
            {
                avg = Math.Max(max, sum / Config.N);
                info.hol = "   Холостой = FALSE";
            }

            info.loadAVG = avg;
            avg++;

            tasks.Sort();
            foreach (CPU c in CPUs)
            {
                foreach (Task t in tasks)
                {
                    if (!t.isEmpty())
                    {
                        if (!c.isLoad(avg))
                        {
                            c.process.Add(t);
                            c.loader += t.time;
                            t.time = 0;
                            info.countTackts++;
                        }

                        if (c.isLoad(avg))
                        {
                            int raz = c.loader - avg;
                            c.loader -= raz;
                            t.time = raz;
                            
                            break;
                        }
                    }
                }
            }

            info.compute();
            return info; 
        }
    }
}
