using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTP
{
    public class CPU
    {
        public static int count = 0;

        public String name { get; set; }
        public int number { get; set; }
        public int loader { get; set; }
        public List<Task> process { get; set; }

        public CPU()
        {
            this.number = CPU.count++;
            this.name = "SPU #" + this.number;
            this.process = new List<Task>();
            this.loader = 0;
        }

        public bool isLoad(int avg)
        {
            return this.loader >= avg;
        }

        public void setDef()
        {
            this.process.Clear();
            this.loader = 0;
        }
    }
}
