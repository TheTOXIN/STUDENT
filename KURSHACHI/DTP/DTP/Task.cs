using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTP
{
    public class Task : IComparable
    {
        public static int count = 0;

        public String name;
        public int number;
        public int time;
        public int tmp;
        public bool isReady;

        public Task()
        {
            this.number = Task.count++;

            if (Program.rand.Next(100) > Config.R)
                this.time = Program.rand.Next(1, Config.M);
            else
                this.time = 0;

            if (this.time == 0)
                this.name = "EMPTY";
            else
                this.name = "Task #" + this.number;

            this.tmp = time;
            this.isReady = false;
        }

        public bool isEmpty()
        {
            return this.time <= 0;
        }

        public bool isShort()
        {
            return this.time <= Config.Q;
        }

        public int CompareTo(object obj)
        {
            Task t = obj as Task;
            if (t != null)
                return this.time.CompareTo(t.time) * -1;
            else
                throw new Exception("Невозможно сравнить два объекта");
        }

        public void setDef()
        {
            this.time = this.tmp;
            this.isReady = false;
        }
    }
}
