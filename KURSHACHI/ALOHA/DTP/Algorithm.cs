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
        private Random r = new Random();

        public List<double> packets = new List<double>();

        public double aloha()
        {
            return Math.Exp(-2 * Config.G);
        }

        public double clearAloha()
        {
            return Math.Exp(-Config.G);
        }

        public Info compute(double P)
        {
            info.clear();

            int c_t = 0;
            int c_f = 0;

            bool f = true;
            for (int i = 0; i < Config.N; i++)
            {
                f = true;
                do
                {
                    double PR = r.NextDouble();
                    packets.Add(PR);
                    if (PR <= P)
                    {
                        c_t++;
                        f = false;
                    }
                    else
                    {
                        info.collision++;
                        c_f++;
                    }
                } while (f);
            }

            double RG = ((c_t + c_f) * Config.U * 1 / Config.I) / Config.N;

            info.e_perfomence = RG * Math.Exp(-2 * RG);
            info.t_perfomence = info.e_perfomence / Config.U;

            info.main_time = (c_t + c_f) * Config.I;
            info.pocket_time = (c_t + c_f) * Config.I / Config.N;

            return info;
        }
    }
}
