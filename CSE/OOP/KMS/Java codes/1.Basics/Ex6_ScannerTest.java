// Scanner Example
// Scanner is a utility class in java.util package
// Used for reading input from keyboard.

import java.util.Scanner;

public class Ex6_ScannerTest {

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        // Read lines until input ends
        while (scn.hasNextLine()) {
            System.out.println(scn.nextLine());
        }

    }

}

/*
Key Notes
---------
Scanner class location:
java.util.Scanner

Common methods:
nextInt()
nextDouble()
nextFloat()
nextLine()

Input source:
System.in
*/