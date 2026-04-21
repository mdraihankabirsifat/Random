// https://github.com/mdraihankabirsifat/Random

public class Ex4_SamePackage {

    Ex4_SamePackage() {
        System.out.println("---SamePackage---");
        Ex2_Protection p = new Ex2_Protection();

        System.out.println(p.n);
        // System.out.println(p.nPrivate); ❌
        System.out.println(p.nProtected);
        System.out.println(p.nPublic);
    }

    public static void main(String[] args) {
        new Ex2_Protection();
        new Ex3_DerivedProtection();
        new Ex4_SamePackage();
    }
}

/*
Key Notes:

1. Same folder (no package) → default works.
2. private still not accessible.
3. Demonstrates object access.
*/
