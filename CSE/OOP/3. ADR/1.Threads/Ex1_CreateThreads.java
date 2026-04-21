// https://github.com/mdraihankabirsifat/Random
//package threads;

public class Ex1_CreateThreads {

    public static void main(String[] args) {
        Ex1_CreateThreads ct = new Ex1_CreateThreads();
        new Thread(ct::f1, "T1").start();
        new Thread(Ex1_CreateThreads::f2, "T3").start(); //if static, no object needed
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
