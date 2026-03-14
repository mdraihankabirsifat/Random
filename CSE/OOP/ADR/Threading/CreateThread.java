public class CreateThread {
    public static void main(String[] args) {
        CreateThread ct1 = new CreateThread();
        new Thread(ct1::f1, "T1").start();
    }

    public void f1() {
        for (int i = 5; i > 0; i--) {
            System.out.println(Thread.currentThread().getName() + " : " + i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}