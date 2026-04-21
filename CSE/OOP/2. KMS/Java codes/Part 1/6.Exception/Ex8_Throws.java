// https://github.com/mdraihankabirsifat/Random
// throws example

public class Ex8_Throws {

    public static void f() throws IllegalAccessException {

        System.out.println("Inside f()");
        throw new IllegalAccessException("f");

    }

    public static void main(String args[]) {

        try {
            f();
        }

        catch(IllegalAccessException e) {
            System.out.println("Inside catch of main()");
            e.printStackTrace();
            //e.getMessage();
        }

    }
}

/*
Key Notes
---------
throws declares exception
that method may produce.
*/
