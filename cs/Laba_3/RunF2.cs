using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Laba_3
{
    class RunF2
    {
        public Thread thread;
        int n;
        private int[][] MK;
        private int[][] MF;
        private int[][] MG;

        public RunF2(int n)
        {
            thread = new Thread(this.Run);
            this.n = n;
            Console.WriteLine("F2 started");
            thread.Priority = ThreadPriority.Highest;
            thread.Start();
        }

        void Run()
        {
            MK = new int[n][];
            MF = new int[n][];
            Data.GenerateMatrix(MK);
            Data.GenerateMatrix(MF);
            MG = Data.F2(MK, MF);
            Console.WriteLine("F2 finished");
        }

        public void PrintResult()
        {
            Console.WriteLine("\nResult of F2: ML = SORT(TRANS(MF)*MK):\n");
            Data.PrintMatrix(MG);
        }
    }
}
