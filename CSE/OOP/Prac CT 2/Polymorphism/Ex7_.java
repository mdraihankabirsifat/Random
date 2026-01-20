public class Main {
    public static void main(String[] args) {
        // Explicit conversion using valueOf()
        Integer iOb1 = Integer.valueOf(100);

        // Auto-Boxing: primitive 150 is automatically wrapped into an Integer object
        Integer iOb2 = 150;

        // Auto Unboxing: iOb1 (Object) is automatically converted to primitive double
        double num1 = iOb1;

        // Explicit Unboxing using intValue()
        int num2 = iOb2.intValue();

        // Arithmetic operations with mixed types
        double sum1 = num1 + num2;
        int sum2 = iOb1 + iOb2; // Both objects are unboxed for the addition

        // Explicit conversion to a specific primitive type
        double num = iOb1.doubleValue();

        // Printing results
        System.out.println("Primitive Sum: " + sum1);
        System.out.println("Object sum: " + sum2);
        System.out.println("Primitive Sum: " + (num1 + num2)); // Corrected: arithmetic before concatenation
        System.out.println("Object sum: " + (iOb1 + iOb2));    // Corrected: arithmetic before concatenation
        System.out.println(num);
    }
}