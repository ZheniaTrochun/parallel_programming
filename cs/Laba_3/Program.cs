using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Laba_3
{
    class Program
    {
        static void Main(string[] args)
        {
            // Console.WriteLine("Input n:");
            // int n = Int32.Parse(Console.ReadLine());

            int n = 100;

            RunF1 f1 = new RunF1(n);
            RunF2 f2 = new RunF2(n);
            RunF3 f3 = new RunF3(n);

            f1.thread.Join();
            f2.thread.Join();
            f3.thread.Join();

            // f1.PrintResult();
            // f2.PrintResult();
            // f3.PrintResult();
        }
    }
}
