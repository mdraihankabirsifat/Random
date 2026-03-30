//
// Provides the main method.
//
// Requester threads are created to request works. These will store
// the work items in the queue
//
// Executor threads are created to execute those works. The workitems will
// be extracted from the queue
// 

import java.util.LinkedList;
import java.util.Queue;

public class App {
    Requester[] rgReq = new Requester[5];
    Executor[] rgExec = new Executor[5];
    Queue<WorkItem> queue = new LinkedList<>();

    public void initRequesters() {
        for (int i = 0; i < rgReq.length; i++) {
            rgReq[i] = new Requester(queue, "Requester " + (i + 1));
            rgReq[i].start();
        }
    }

    public void initExecutors() {
        for (int i = 0; i < rgReq.length; i++) {
            rgExec[i] = new Executor(queue, "Executor " + (i + 1));
            rgExec[i].start();
        }
    }

    public void shutDownRequesters() {
        for (Requester req : rgReq) {
            req.signalShutDown();
            try {
                req.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void shutDownExecutors() {
        for (Executor exec : rgExec) {
            exec.signalShutDown();
            try {
                exec.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public int getQueuedWorkItemCount() {
        return ((LinkedList<WorkItem>) queue).size();
    }

    public static void main(String[] args) throws Exception {
        App app = new App();

        app.initRequesters();
        app.initExecutors();

        // We do a simulation of work request and execution for 10 seconds.
        Thread.sleep(10000);
        app.shutDownRequesters();
        app.shutDownExecutors();

        System.out.println("Jobs remaining in the queue: " + app.getQueuedWorkItemCount());
    }
}
