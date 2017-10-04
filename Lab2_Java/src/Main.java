public class Main {

    public static void main(String[] args) throws InterruptedException {

        Data d = new Data(750);

        Task1 t1 = new Task1(d);
        Task2 t2 = new Task2(d);
        Task3 t3 = new Task3(d);

        Thread f1 = new Thread(t1);
        Thread f2 = new Thread(t2);
        Thread f3 = new Thread(t3);

        f1.start();
        f2.start();
        f3.start();

        f1.join();
        f2.join();
        f3.join();

        t1.printResult();
        t2.printResult();
        t3.printResult();
    }
}
