public class ThreadsOnline {

    static MyThread[] rgThreads = new MyThread[500];

    public static void main(String[] args) {
        MDSRHeaveyCompute hc = new MDSRHeaveyCompute();
        MyMTAObject mta = new MyMTAObject(hc);
        long startTime, endTime;

        for (int i = 0; i < rgThreads.length; i++) {
            rgThreads[i] = new MyThread(mta, "MyThread " + Integer.toString(i + 1));
        }

        startTime = System.currentTimeMillis();
        for (Thread t : rgThreads) {
            t.start();
            System.out.println("Started thread " + t.getName());
        }

        //
        // Write appropriate code to Wait until all the created threads are done
        //
        for (Thread t : rgThreads) {
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        endTime = System.currentTimeMillis();
        System.out.println("Tasks completed in " + 1.0 * (endTime - startTime) / 1000 + " seconds.");
        hc.reportSanity();

        for (Thread t : rgThreads) {
            if (t.isAlive()) {
                System.out.println("Error!!! " + t.getName() + " is still alive.");
            }
        }
    }
}
