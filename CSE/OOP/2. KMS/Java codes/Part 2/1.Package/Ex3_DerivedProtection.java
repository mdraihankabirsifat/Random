// https://github.com/mdraihankabirsifat/Random
public class Ex3_DerivedProtection extends Ex2_Protection {

    Ex3_DerivedProtection() {
        System.out.println("---DerivedProtection---");
        System.out.println(n);
        // System.out.println(nPrivate); ❌
        System.out.println(nProtected);
        System.out.println(nPublic);
    }
}

/*
Key Notes:

1. Inheritance using extends.
2. private not accessible.
3. protected accessible.
*/
