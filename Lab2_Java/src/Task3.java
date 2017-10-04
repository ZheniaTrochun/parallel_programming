import java.util.Arrays;

/**
 * Created by Makarenko on 25.09.2017.
 */
public class Task3 implements Runnable{
    private Data data;
    private int result;

    public Task3(Data data) {
        this.data = data;
    }

    public int getResult() {
        return result;
    }

    public void printResult() {
        System.out.println("\nTask3 result: " + result + '\n');
    }

//    t = MAX((MO*MP)*R + MS*S)
    @Override
    public void run() {
        System.out.println("Task3 started");

        int[] S = data.GetRandomVector();
        int[] R = data.GetRandomVector();

        int[][] MS = data.GetRandomMatrix();
        int[][] MO = data.GetRandomMatrix();
        int[][] MP = data.GetRandomMatrix();

        MO = data.multiplyMatrix(MO, MP);

        int[][] Temp = new int[data.length][];
        for(int i=0;i<data.length; i++){
            Temp[i] = new int[data.length];
            for(int j=0;j<data.length;j++)
                Temp[i][j] = 0;
        }

        Temp[0] = R;

        MO = data.multiplyMatrix(MO, Temp);

        Temp[0] = S;
        MS = data.multiplyMatrix(MS, Temp);

        MS = data.SumvMatrix(MS, MO);

        result = data.max(MS);

        System.out.println("Task3 finished");
    }

}
