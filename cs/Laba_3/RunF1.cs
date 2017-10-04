using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

// d = ((A + B)* (C *(MA*ME)))
namespace Laba_3
{
    class RunF1
    {
        public Thread thread;
        int n;
        int d;
        private int[] B;
        private int[] A;
        private int[] C;
        private int[][] MA;
        private int[][] ME;

        public RunF1(int n)
        {
            thread = new Thread(this.Run);
            this.n = n;
            Console.WriteLine("F1 started");
            thread.Start();
        }

        void Run()
        {
            A = new int[n];
            B = new int[n];
            C = new int[n];
            MA = new int[n][];
            ME = new int[n][];
            Data.GenerateVector(A);
            Data.GenerateVector(B);
            Data.GenerateVector(C);
            Data.GenerateMatrix(MA);
            Data.GenerateMatrix(ME);
            d = Data.F1(A, B, C, MA, ME);
            Console.WriteLine("F1 finished");
        }

        public void PrintResult()
        {
            Console.WriteLine("\nResult of F1: d = ((A + B)* (C *(MA*ME))):\n" + d);
        }
    }
 }
