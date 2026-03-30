public interface HeavyCompute {
    //
    // Returns a certificate to do computation.
    // You will have to pass this certificate to the compute() method
    //
    public String getCertificate();

    //
    // Perform computation. The passed in certificate (cert) must be a certificate
    // that was obtained using a call to getCertificate().
    // NOTE: One certificate can be used only for single computation
    //
    public boolean compute(String cert);
}
