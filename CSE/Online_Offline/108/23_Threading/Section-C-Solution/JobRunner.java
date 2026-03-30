import java.util.LinkedList;
import java.util.Queue;

//
// Maintains a queue of workitems. Executes the workitems
// one by one in single thread. Such pattern is useful when
// the target of the work can only handle single threaded actions
// For example, most ot the UI platforms expect notifications to
// come through the UI thread.
//

public class JobRunner extends Thread {
    // Queue of work items.
    private Queue<WorkItem> queue = new LinkedList<>();

    // Whether termination of the JobRunner has been signalled
    private boolean fQuit = false;

    JobRunner() {
        super("JobRunner");
    }

    public void enqueue(WorkItem work) {
        //
        // Use queue.add method to enqueue the work item
        // The underlying queue is not threadsafe. So we need to
        // take appropriate measure(s).
        //
        synchronized (this) {
            queue.add(work);
        }
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
        // Execution of the Job Queue thread begins
        //
        // Run an infinite loop. If there is work to do, we perform it
        // Otherwise, we go to sleep for a second and try again. However,
        // if shutdown has been signalled, then we break the infinite loop
        //
        while (true) {
            boolean fQuit = false;
            synchronized (this) {
                fQuit = this.fQuit;
            }
            if (fQuit) {
                break;
            }
            WorkItem workitem = queue.poll();
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
