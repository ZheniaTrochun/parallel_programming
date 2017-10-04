
public class Task1 implements Runnable {
    private Data data;
    private int result;

    public Task1(Data data) {
        this.data = data;
    }

    public int getResult() {
        return result;
    }

    public void printResult() {
        System.out.println("\nTask1 result: " + result);
    }

//    d = ((A + B)* (C *(MA*ME)))
    @Override
    public void run() {
        System.out.println("Task1 started");
        int[] C = data.GetRandomVector();


        int[] A = data.GetRandomVector();
        int[] B = data.GetRandomVector();
        int[][] MA = data.GetRandomMatrix();
        int[][] ME = data.GetRandomMatrix();
        int[][] MD = data.GetRandomMatrix();

        int[][] TMP = new int[ME.length][ME[0].length];
        TMP[0] = C;

        MA = data.multiplyMatrix(MA, ME);
        MA = data.multiplyMatrix(TMP, MA);

        A = data.SumVector(A, B);

        result = data.dotProduct(A, MA[0]);


        System.out.println("Task1 finished");
    }
}
