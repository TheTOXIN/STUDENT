using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTP
{
    public class Config
    {
        public static double G = 0;//нагрузка
        public static int I = 0;//интервал
        public static int N = 10;//кол-во пакетов
        public static int U = 0;//кол-во процессоров

        public static void setExp1()
        {
            Config.G = 0.01;
            Config.I = 1;
            Config.N = 10;
            Config.U = 1;
        }

        public static void setExp2()
        {
            Config.G = 0.5;
            Config.I = 4;
            Config.N = 10;
            Config.U = 2;
        }

        public static void setExp3()
        {
            Config.G = 1.2;
            Config.I = 8;
            Config.N = 10;
            Config.U = 4;
        }

        public static void setExp4()
        {
            Config.G = 2.0;
            Config.I = 20;
            Config.N = 10;
            Config.U = 8;
        }
    }
}
