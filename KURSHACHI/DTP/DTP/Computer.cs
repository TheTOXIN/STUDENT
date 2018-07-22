using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTP
{
    public class Computer
    {
        private Algorithm algrtm;
        public List<CPU> CPUs;
        public List<Task> tasks;

        public Computer()
        {
            this.algrtm = new Algorithm();
            this.CPUs = new List<CPU>();
            this.tasks = new List<Task>();
        }

        public void dflt()
        {
            foreach (Task t in tasks)
                t.setDef();
            foreach (CPU c in CPUs)
                c.setDef();
        }

        public void init()
        {
            for (int i = 0; i < Config.C; i++)
                tasks.Add(new Task());
            for (int i = 0; i < Config.N; i++)
                CPUs.Add(new CPU());
        }

        public void update()
        {
            CPUs.Clear();
            tasks.Clear();
            CPU.count = 0;
            Task.count = 0;
        }

        public Info computeSPT()
        {
            return algrtm.SPT(tasks, CPUs);
        }

        public Info computeRR()
        {
            return algrtm.RR(tasks, CPUs);
        }

        public Info computeLPT()
        {
            return algrtm.LPT(tasks, CPUs);
        }

        public Info computeMAK()
        {
            return algrtm.MAK(tasks, CPUs);
        }

        public void sortTasks()
        {
            tasks.Sort();
        }
    }
}
