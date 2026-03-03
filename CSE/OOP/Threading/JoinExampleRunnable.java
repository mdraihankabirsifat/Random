
public class JoinExampleRunnable {

    static class MyTask implements Runnable {

        String name;

        MyTask(String name) {
            this.name = name;
        }

        @Override
        public void run() {
            for (int i = 5; i > 0; i--) {
                System.out.println(name + ": " + i);
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                }
            }
        }
    }

    public static void
            main(String[] args) throws Exception {

        Thread t1 = new Thread(new MyTask("T1"));
        Thread t2 = new Thread(new MyTask("T2"));

        t1.start();
        t2.start();
        t1.join(); // wait until T1 finishes
        t2.join(); // optional but cleaner

        System.out.println("Main thread finished last.");
    }
}
