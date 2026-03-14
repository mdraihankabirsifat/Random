
public class IsAliveExample {

    public static void main(String[] args) throws Exception {

        Thread t = new Thread(() -> {
            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
            }
        });

        t.start();
        
        while (t.isAlive()) {
            System.out.println("Thread is still running...");
            Thread.sleep(1000);
        }

        System.out.println("Thread has finished.");
    }
}
