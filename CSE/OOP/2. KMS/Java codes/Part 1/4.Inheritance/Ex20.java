// https://github.com/mdraihankabirsifat/Random

class StaticTest {

    static int x = 5, y;
    int z = 10;

    static {
        y = x * 4;
    }

    int s1() {
        return x * y;
    }

    static void s2() {
        System.out.println("x = " + x);
        System.out.println("y = " + y);
        // cannot print z directly here
    }

    public static void main(String[] args) {
        StaticTest obj = new StaticTest();

        System.out.println("s1 = " + obj.s1());
        System.out.println("x = " + x);
        System.out.println("z = " + obj.z);

        s2();
    }
}

public class Ex20 {
}