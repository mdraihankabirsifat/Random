public class MultipleThreads {

    public static void main(String[] args) {

        Runnable task1 = () -> {
            for (int i = 5; i > 0; i--) {
                System.out.println("Thread-1: " + i);
                try { Thread.sleep(500); } 
                catch (InterruptedException e) { }
            }
        };

        Runnable task2 = () -> {
            for (int i = 5; i > 0; i--) {
                System.out.println("Thread-2: " + i);
                try { Thread.sleep(500); } 
                catch (InterruptedException e) { }
            }
        };

        Thread t1 = new Thread(task1);
        Thread t2 = new Thread(task2);

        t1.start();
        t2.start();

        System.out.println("Main thread finished.");
    }
}