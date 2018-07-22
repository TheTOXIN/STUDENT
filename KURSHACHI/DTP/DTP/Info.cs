using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTP
{
    public class Info
    {
        public int countShort = 0;
        public int countLong = 0;
        public int countTackts = 0;
        public int countEmpty = 0;
        public int loadAVG = 0;

        public double timeShort = 0;
        public double timeAVG = 0;

        public void clear()
        {
            countShort = 0;
            countLong = 0;
            countTackts = 0;
            countEmpty = 0;

            timeShort = 0;
            timeAVG = 0;
        }

        public void compute()
        {
            countLong = countTackts - countShort;
            timeShort = countShort * Config.L;
            timeAVG = countShort / (double)(Config.C - countEmpty);
        }
    }
}
