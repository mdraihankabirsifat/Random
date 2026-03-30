public class MyThread extends Thread {
    MyMTAObject mta = null;

    MyThread(MyMTAObject mta, String threadName) {
        super(threadName);
        this.mta = mta;
    }

    public void run() {
        mta.doCompute();
        // mta.doComputeSync(); // see the tasks completed time with this
    }
}
