// String Conversion Example

public class Ex6_Conversion {

    public static void main(String[] args) {

        int n = 123;

        String s1 = Integer.toString(n);
        String s2 = String.valueOf(n);
        String s3 = n + "";

        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3);

        String s = "1234";

        int x = Integer.parseInt(s);

        System.out.println(x);

    }
}

/*
Key Notes
---------
int → String
Integer.toString()
String.valueOf()

String → int
Integer.parseInt()
 */