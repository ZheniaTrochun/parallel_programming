/**
 * Created by Makarenko on 25.09.2017.
 */
public class Task2 implements Runnable{
    private Data data;
    private int[][] result;

    public Task2(Data data) {
        this.data = data;
    }

    public int[][] getResult() {
        return result;
    }

    public void printResult() {
        System.out.println("\nTask2 result:");
        data.printMatrix(result);
    }

// ML = SORT(TRANS(MF)*MK)
    @Override
    public void run() {
        System.out.println("Task2 started");


        int[][] MF = data.GetRandomMatrix();
        int[][] MK = data.GetRandomMatrix();

        MF = data.TransMatrix(MF);

        MF = data.multiplyMatrix(MF, MK);

        for (int i = 0; i < MF.length; i++) {
            MF[i] = data.sortVector(MF[i]);
        }

        result = MF;

        System.out.println("Task2 finished");
    }
}
