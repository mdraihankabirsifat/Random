// https://github.com/mdraihankabirsifat/Random
public class Ex2_Protection {
    int n = 1;
    private int nPrivate = 2;
    protected int nProtected = 3;
    public int nPublic = 4;

    public Ex2_Protection() {
        System.out.println("---Protection---");
        System.out.println(n);
        System.out.println(nPrivate);
        System.out.println(nProtected);
        System.out.println(nPublic);
    }
}

/*
Key Notes:

1. Demonstrates all access modifiers:
   - default → same package
   - private → only inside class
   - protected → same package + subclass
   - public → everywhere
*/