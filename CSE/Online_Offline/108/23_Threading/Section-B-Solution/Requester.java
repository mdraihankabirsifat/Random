
//
// Job Requester
//
import java.util.Queue;

public class Requester extends Thread {
    // For giving unique id to each new work item
    static private Integer workItemId = 0;

    // Queue of work items.
    private Queue<WorkItem> queue = null;

    // Whether termination of the Requester has been signalled
    private boolean fQuit = false;

    public Requester(Queue<WorkItem> queue, String name) {
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
        // Requester thread begins.
        //
        // Run an infinite loop.
        // If shutdown has been signalled, then we break the infinite loop
        //
        // Otherwise, Use queue.add method to enqueue the work item
        // The underlying queue is not threadsafe. So we need to
        // take appropriate measure(s). Afterwards, we go to sleep for 100 ms.
        //
        boolean fQuit = false;
        boolean fResult = false;
        WorkItem workitem = null;
        while (true) {
            synchronized (this) {
                fQuit = this.fQuit;
            }
            if (fQuit) {
                break;
            }

            synchronized (queue) {
                workitem = new MTAWorkItem(++workItemId);
                fResult = queue.add(workitem);
            }
            if (fResult) {
                //
                // If the work was successfully added, we write a log statement.
                //
                System.out.println("" + Thread.currentThread().getName() + ">> Added work item: " + workitem.getId());
            }

            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

}
