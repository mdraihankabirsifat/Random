public class MyMTAObject {
    private HeavyCompute hc = null;

    public MyMTAObject(HeavyCompute hc) {
        this.hc = hc;
    }

    public void doCompute() {
        String cert;

        synchronized (this) {
            cert = hc.getCertificate();
        }

        hc.compute(cert);
    }

    /*
     * public synchronized void doComputeSync() {
     * String cert = hc.getCertificate();
     * hc.compute(cert);
     * }
     */
}
