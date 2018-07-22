using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DTP
{
    public class Program
    {
        public static Random rand = new Random();

        public static void Main(string[] args)
        {
            Console.WriteLine("-=DTP=-");
            Console.WriteLine();

            Computer comp = new Computer();
            VIew.config();

            Info infoSPT = comp.computeSPT();
            VIew.showSPT(comp);
            VIew.show(infoSPT);

            comp.dflt();

            Info infoRR = comp.computeRR();
            VIew.showRR(comp);
            VIew.show(infoRR);

            comp.dflt();

            Info infoMAK = comp.computeMAK();
            VIew.showMAK(comp);
            VIew.show(infoMAK);

            comp.dflt();

            Info infoLPT = comp.computeLPT();
            VIew.showLPT(comp);
            VIew.show(infoLPT);

            comp.dflt();

            Console.ReadKey();
        }
    }
}
