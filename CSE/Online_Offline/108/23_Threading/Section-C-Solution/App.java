public class App implements Runnable {
    private int workItemId = 0;
    private JobRunner runner = new JobRunner();

    public void startJobRunner() {
        runner.start();
    }

    public void terminateJobRunner() {
        //
        // Signal termination of the job runner
        // and wait for it to completely shutdown
        //
        runner.signalShutDown();

        try {
            runner.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void run() {
        //
        // Create a new work item.
        // Ensure that it is executed in the JobRunner thread
        //
        int id;
        synchronized (this) {
            id = ++workItemId;
        }
        WorkItem workitem = new STAWorkItem(id);
        runner.enqueue(workitem);
    }

    public static void main(String[] args) throws Exception {
        App app = new App();

        app.startJobRunner();
        for (int i = 0; i < 500; i++) {
            new Thread(app, "WorkGeneratorThread " + Integer.toString(i + 1)).start();
        }

        Thread.sleep(20000);
        app.terminateJobRunner();
    }
}
