
public class JoinExample {

    public static void main(String[] args) throws Exception {

        Thread t1 = new Thread(() -> {
            for (int i = 5; i > 0; i--) {
                System.out.println("T1: " + i);
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                }
            }
        });

        Thread t2 = new Thread(() -> {
            for (int i = 5; i > 0; i--) {
                System.out.println("T2: " + i);
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                }
            }
        });

        t1.start();
        t1.join();
        t2.start();

        System.out.println("Main thread finished last.");
    }
}
