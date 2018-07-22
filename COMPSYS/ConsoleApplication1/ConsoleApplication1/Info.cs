using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

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

        public String hol;

        public void clear()
        {
            countShort = 0;
            countLong = 0;
            countTackts = 0;
            countEmpty = 0;

            timeShort = 0;
            timeAVG = 0;

            hol = "";
        }

        public void compute()
        {
            countLong = countTackts - countShort;
            timeShort /= countShort;
            timeAVG /= (double)Config.L;
        }
    }
}
