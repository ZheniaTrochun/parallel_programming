
import java.util.Arrays;
import java.util.Random;

public class Data {
    int length;

    public void printVector(int[] v1){
        for(int i=0;i< length;i++)
            System.out.print(v1[i]+" ");
        System.out.println();
    }

    public void printMatrix(int[][] m1){
        for(int i=0;i< length;i++)
            printVector(m1[i]);
        System.out.println();
    }

    public Data(int n){
        length = n;
    }

    public int GetRandomNumber(){
        Random rand = new Random();
        return  rand.nextInt();
    }

    public int[][] TransMatrix(int[][] m) {
        int[][] res = new int[m[0].length][m.length];

        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m[0].length; j++) {
                res[j][i] = m[i][j];
            }
        }

        return res;
    }

    public int[] GetRandomVector(){
        int[] result = new int[length];
        for(int i=0;i<length ;i++)
            result[i] = GetRandomNumber();
        return  result;
    }

    public int[][] GetRandomMatrix(){
        int result[][] = new int[length][];
        for(int i=0;i<length;i++)
            result[i]= GetRandomVector();
        return result;
    }

    public int[] SumVector(int[] v1, int[] v2){
        int[] result = new int[length];
        for(int i=0;i<length;i++)
            result[i] = v1[i]+v2[i];
        return  result;
    }

    public int[][] SumvMatrix(int[][] m1, int[][] m2){
        int[][] result = new int[length][];
        for (int i=0;i<length;i++)
            result[i] = SumVector(m1[i], m2[i]);
        return result;
    }

    public int dotProduct(int[] v1, int[] v2){
        int result = 0;
        for(int i=0;i<length;i++)
            result+=v1[i]*v2[i];
        return  result;
    }

    public int[] sortVector(int[] arr){
        int temp;

        for (int i = 0; i < length - 1; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        return arr;
    }

    public int[][] multiplyMatrix(int[][] m1, int[][] m2){
        int[][] result = new int[length][];
        for (int i = 0; i < length; i++)
            result[i] = new int[length];
        for (int k = 0; k < length; k++)
        {
            for (int i = 0; i < length; i++)
            {
                int t = 0;
                for (int j = 0; j < length; j++)
                    t += m1[i][j] * m2[j][k];
                result[i][k] = t;
            }
        }
        return result;
    }

    public int max(int[][] m) {
        return Arrays.stream(m).mapToInt(arr -> Arrays.stream(arr).max().getAsInt()).max().getAsInt();
    }
}