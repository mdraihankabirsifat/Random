//
// Do not remove any line of code. 
// Make changes following instructions in the TODO remarks
//

public class App implements Runnable {
    private int workItemId = 0;
    private JobRunner runner = new JobRunner();

    public void startJobRunner() {
        runner.start();
    }

    public void terminateJobRunner() {
        //
        // TODO: Signal termination of the job runner
        // and wait for it to completely shutdown
        //
    }

    public void run() {
        //
        // TODO: Create a new work item.
        // Ensure that it is executed in the JobRunner thread
        // The Ids of the work item needs to be distinct 
    }

    public static void main(String[] args) throws Exception {
        App app = new App();

        app.startJobRunner();
        for (int i = 0; i < 500; i++) {
            new Thread(app, "WorkGeneratorThread " + Integer.toString(i+1)).start();
        }

        Thread.sleep(20000);
        app.terminateJobRunner();
    }
}
