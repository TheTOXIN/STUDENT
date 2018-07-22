using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTP
{
    public class Info
    {
        public double t_perfomence = 0;
        public double e_perfomence = 0;
        public int collision = 0;
        public double main_time = 0;
        public double pocket_time = 0;

        public void clear()
        {
            t_perfomence = 0;
            e_perfomence = 0;
            collision = 0;
            main_time = 0;
            pocket_time = 0;
        }
    }
}
