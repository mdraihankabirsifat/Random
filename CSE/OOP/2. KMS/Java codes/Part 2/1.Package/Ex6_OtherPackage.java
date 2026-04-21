// https://github.com/mdraihankabirsifat/Random
public class Ex6_OtherPackage {
    Ex6_OtherPackage() {
        System.out.println("---OtherPackage---");
        Ex2_Protection p = new Ex2_Protection();

        System.out.println(p.n);
        System.out.println(p.nProtected);
        System.out.println(p.nPublic);
    }

    public static void main(String[] args) {
        new Ex5_Protection2();
        new Ex6_OtherPackage();
    }
}

/*
Key Notes:

1. Since no package → behaves same package.
2. default and protected now accessible.
3. private still restricted.
*/