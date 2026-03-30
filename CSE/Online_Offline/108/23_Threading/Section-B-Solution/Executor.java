
//
// Job Executor 
//
import java.util.Queue;

public class Executor extends Thread {
    // Queue of work items.
    private Queue<WorkItem> queue = null;

    // Whether termination of the Executor has been signalled.
    private boolean fQuit = false;

    public Executor(Queue<WorkItem> queue, String name) {
        super(name);
        this.queue = queue;
    }

    public void signalShutDown() {
        //
        // Record that shutdown has been signalled.
        //
        synchronized (this) {
            fQuit = true;
        }
    }

    public void run() {
        //
        // Executor thread begins
        //
        // Run an infinite loop. If there is work to do, we perform it
        // Otherwise, we go to sleep for a second and try again. However,
        // if shutdown has been signalled, then we break the infinite loop
        //

        boolean fQuit = false;
        WorkItem workitem = null;
        while (true) {
            synchronized (this) {
                fQuit = this.fQuit;
            }
            if (fQuit) {
                break;
            }

            synchronized (queue) {
                workitem = queue.poll();
            }
            if (workitem == null) {
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                continue;
            }

            if (workitem.work()) {
                //
                // If the work was successfully performed, we write a log statement.
                //
                System.out
                        .println("" + Thread.currentThread().getName() + ">> Finished work item: " + workitem.getId());
            }
        }

    }
}
