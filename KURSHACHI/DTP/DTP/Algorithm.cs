using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTP
{
    public class Algorithm
    {
        private Info info = new Info();

        public Info SPT(List<Task> tasks, List<CPU> CPUs)
        {
            info.clear();

            Task[] ar = tasks.ToArray();

            for (int i = 0; i < ar.Length; i++)
            {
                if (!ar[i].isEmpty())
                {
                    info.countTackts++;
                    if (ar[i].isShort())
                    {
                        info.countShort++;
                        ar[i].time = 0;
                    }
                    else
                    {
                        while (!ar[i].isShort())
                        {
                            info.countTackts++;
                            ar[i].time -= Config.Q;
                        }
                    }

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

            for (int i = 0; i < ar.Length; i++)
                if (ar[i].isEmpty())
                {
                    info.countEmpty++;
                }
                else
                    if (ar[i].isShort())
                        info.countShort++;

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
                            ar[i].time = 0;
                        }
                        else
                        {
                            ar[i].time -= Config.Q;
                        }
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
            {
                sum += t.time;
                if (max <= t.time)
                    max = t.time;
            }

            avg = Math.Max(max, sum / Config.N) + 1;
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
                        }

                        if (c.isLoad(avg))
                        {
                            int raz = c.loader - avg;
                            c.loader -= raz;
                            t.time = raz;

                            break;
                        }
                    }
                    else
                        info.countEmpty++;
                }
            }

            info.compute();
            return info;
        }
    }
}
