using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Laba_3
{
    class RunF3
    {
        public Thread thread;
        int n;
        private int t;
        private int[] S;
        private int[][] MP;
        private int[][] MO;
        private int[][] MS;
        private int[] R;

        public RunF3(int n)
        {
            thread = new Thread(this.Run);
            this.n = n;
            thread.Priority = ThreadPriority.Lowest;
            Console.WriteLine("F3 started");
            thread.Start();
        }

        void Run()
        {
            S = new int[n];
            R = new int[n];
            MP = new int[n][];
            MO = new int[n][];
            MS = new int[n][];
            Data.GenerateVector(R);
            Data.GenerateVector(S);
            Data.GenerateMatrix(MP);
            Data.GenerateMatrix(MO);
            Data.GenerateMatrix(MS);
            t = Data.F3(MO, MP, MS, R, S);
            Console.WriteLine("F3 finished");
        }

        public void PrintResult()
        {
            Console.WriteLine("\nRResult of F3: t = MAX((MO*MP)*R + MS*S):\n" + t);
        }
    }
}
