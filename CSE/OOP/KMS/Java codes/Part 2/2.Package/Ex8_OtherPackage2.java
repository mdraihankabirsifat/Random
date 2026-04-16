public class Ex8_OtherPackage2 {
    Ex8_OtherPackage2() {
        System.out.println("---OtherPackage---");
        Ex2_Protection p = new Ex2_Protection();

        System.out.println(p.n);
        System.out.println(p.nProtected);
        System.out.println(p.nPublic);
    }

    public static void main(String[] args) {
        new Ex7_Protection3();
        new Ex8_OtherPackage2();
    }
}

/*
Key Notes:

1. No package → everything is same scope.
2. All except private accessible.
*/