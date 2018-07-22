using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DTP
{
    public class Config
    {
        public static int R = 0;//вероятность короткой задачи
        public static int M = 0;//время максимальной задачи
        public static int Q = 0;//квант за 1 такт
        public static int C = 0;//кол-во задач
        public static int N = 0;//кол-во процс
        public static int L = 0;//время для задачи

        public static void setExp1()
        {
            Config.R = 10;
            Config.M = 6;
            Config.Q = 3;
            Config.C = 10;
            Config.N = 2;
            Config.L = 6;
        }

        public static void setExp2()
        {
            Config.R = 2;
            Config.M = 6;
            Config.Q = 3;
            Config.C = 10;
            Config.N = 2;
            Config.L = 6;
        }

        public static void setExp3()
        {
            Config.R = 3;
            Config.M = 6;
            Config.Q = 3;
            Config.C = 10;
            Config.N = 2;
            Config.L = 6;
        }

        public static void setExp4()
        {
            Config.R = 4;
            Config.M = 6;
            Config.Q = 3;
            Config.C = 10;
            Config.N = 2;
            Config.L = 6;
        }
    }
}
