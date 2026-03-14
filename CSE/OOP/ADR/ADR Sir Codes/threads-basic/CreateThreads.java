//package threads;

public class CreateThreads {

    public static void main(String[] args) {
        CreateThreads ct = new CreateThreads();
        new Thread(ct::f1, "T1").start();
        new Thread(CreateThreads::f2, "T3").start(); //if static, no object needed
    }

    public void f1() {
        for (int i = 10; i > 0; i--) {
            System.out.println("f1(): " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }

    public static void f2() {
        for (int i = 10; i > 0; i--) {
            System.out.println("f2(): " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }

}
