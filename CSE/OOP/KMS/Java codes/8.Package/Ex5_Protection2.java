
public class Ex5_Protection2 extends Ex2_Protection {

    Ex5_Protection2() {
        System.out.println("---Protection2---");
        System.out.println(n); // works now (same folder)
        System.out.println(nProtected);
        System.out.println(nPublic);
    }
}

/*
Key Notes:

1. No package → everything behaves as SAME PACKAGE.
2. default + protected + public accessible.
3. private still not accessible.
*/
