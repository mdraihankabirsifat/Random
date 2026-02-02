
public class reference {

    // Fields (Instance variables)
    int L, W, H;

    // Constructor (MUST match class name 'reference')
    reference(int l, int w, int h) {
        L = l;
        W = w;
        H = h;
    }

    // toString method for easy printing
    public String toString() {
        return "(" + L + ", " + W + ", " + H + ")";
    }

    public static void main(String[] args) {
        reference b1; // Type must be 'reference', not 'Box'
        reference b2;

        // 1. Allocate memory
        b1 = new reference(8, 5, 7); // Constructor call must match class name
        System.out.println("b1: " + b1);

        // 2. Reference Copy
        b2 = b1;
        System.out.println("b2 points to b1's object: " + b2);

        // 3. Re-assignment
        b1 = new reference(3, 9, 2);
        System.out.println("b1 is now a new object: " + b1);
        System.out.println("b2 still points to the old object: " + b2);

        // 4. Reference Copy again
        b1 = b2;
        System.out.println("b1 points back to b2's object: " + b1);
    }
}
