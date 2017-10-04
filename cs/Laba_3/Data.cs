using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba_3
{
    class Data
    {
        private static Random random = new Random();

// d = ((A + B)* (C *(MA*ME)))
        public static int F1(int[] A, int[] B, int[] C, int[][] MA, int[][] ME)
        {
            int[] vector = VectorSum(A, B);
            MA = MatrixMult(MA, ME);

            int[][] Temp = new int[A.Length][];

            for (int i = 0; i < A.Length; i++) {
                Temp[i] = new int[A.Length];
                for (int j = 0; j < A.Length; j++)
                  Temp[i][j] = 0;
            }

            Temp[0] = C;

            MA = MatrixMult(Temp, MA);

            return VectorMult(vector, MA[0]);
        }

// ML = SORT(TRANS(MF)*MK)
        public static int[][] F2(int[][] MF, int[][] MK)
        {
            MF = TransMatrix(MF);
            MF = MatrixMult(MF, MK);
            MF = SortMatrix(MF);
            return MF;
        }

// t = MAX((MO*MP)*R + MS*S)
        public static int F3(int[][] MO, int[][] MP, int[][] MS, int[] R, int[] S)
        {
            MO = MatrixMult(MO, MP);

            int[][] Temp = new int[R.Length][];

            for (int i = 0; i < R.Length; i++) {
                Temp[i] = new int[R.Length];
                for (int j = 0; j < R.Length; j++)
                  Temp[i][j] = 0;
            }

            Temp[0] = R;
            MO = MatrixMult(MO, Temp);

            Temp[0] = S;
            MS = MatrixMult(MS, Temp);

            MO = SumMatrix(MO, MS);

            return MaxMatrix(MO);
        }

        public static void GenerateVector(int[] vector)
        {
            for (int i = 0; i < vector.Length; i++)
                vector[i] = random.Next(5);
        }

        public static void GenerateMatrix(int[][] matrix)
        {
            for (int i = 0; i < matrix.Length; i++)
            {
                matrix[i] = new int[matrix.Length];
                GenerateVector(matrix[i]);
            }
        }

        public static int[][] SortMatrix(int[][] m)
        {
            for (int i = 0; i < m.Length; i++)
                Array.Sort(m[i]);

            return m;
        }

        public static int[][] SumMatrix(int[][] m1, int[][] m2)
        {
          int[][] res = new int[m1[0].Length][];

          for (int i = 0; i < m1.Length; i++)
              res[i] = new int[m1[0].Length];

          for (int i = 0; i < m1.Length; i++)
              for (int j = 0; j < m1[0].Length; j++)
                  res[i][j] = m1[i][j] + m2[i][j];

          return res;
        }

        public static int[][] TransMatrix(int[][] m)
        {
            int[][] res = new int[m[0].Length][];

            for (int i = 0; i < m.Length; i++)
                res[i] = new int[m[0].Length];

            for (int i = 0; i < m.Length; i++)
                for (int j = 0; j < m[0].Length; j++)
                    res[j][i] = m[i][j];

            return res;
        }

        public static int[][] MatrixMult(int[][] A, int[][] B)
        {
            int[][] result = new int[A.Length][];

            for (int i = 0; i < A.Length; i++)
            {
                result[i] = new int[A.Length];
                for (int j = 0; j < A.Length; j++)
                {
                    for (int r = 0; r < A.Length; r++)
                    {
                        result[i][j] += A[i][r] * B[r][j];
                    }
                }
            }

            return result;
        }

        public static int VectorMult(int[] A, int[] B)
        {
            int result = 0;
            for (int i = 0; i < A.Length; i++)
                result += A[i] * B[i];
            return result;
        }

        public static int[] VectorSum(int[] A, int[] B)
        {
            int[] result = new int[A.Length];
            for (int i = 0; i < A.Length; i++)
                result[i] = A[i] + B[i];
            return result;
        }

        public static int[] VectorMultInt(int[] A, int a)
        {
            int[] result = new int[A.Length];
            for (int i = 0; i < A.Length; i++)
                result[i] += A[i] * a;
            return result;
        }

        public static int[][] MatrixMultInt(int[][] A, int a)
        {
            int[][] result = new int[A.Length][];
            for (int i = 0; i < A.Length; i++)
                result[i] = VectorMultInt(A[i], a);
            return result;
        }

        public static int MaxVector(int[] A)
        {
            int max = A[0];

            for (int i = 1; i < A.Length; i++)
            {
                if (max < A[i])
                    max = A[i];
            }
            return max;
        }

        public static int MaxMatrix(int[][] A)
        {
            int max = A[0][0];

            for (int i = 0; i < A.Length; i++)
            {
                for (int j = 0; j < A.Length; j++)
                {
                    if (max < A[i][j])
                        max = A[i][j];
                }
            }

            return max;
        }

        public static void PrintMatrix(int[][] A)
        {
            for (int i = 0; i < A.Length; i++)
            {
                for (int j = 0; j < A.Length; j++)
                {
                    Console.Write(A[i][j] + " ");
                }
                Console.WriteLine();
            }
        }

        public static void PrintVector(int[] A)
        {
            for (int i = 0; i < A.Length; i++)
                Console.Write(A[i] + " ");
            Console.WriteLine();
        }
    }
}
