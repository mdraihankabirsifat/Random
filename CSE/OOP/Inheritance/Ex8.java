// Class containing a nested interface
class A
{
    // Nested interface: must be referred to as A.Nested outside this class
public
    interface Nested
    {
    public
        boolean isNegative(int x);
    }
}

// Interface extending a nested interface
// Note: Must use the fully qualified name A.Nested
interface inNested extends A.Nested
{
public
    void print(String str);
}

// Class implementing both the parent and child interfaces
class B implements inNested, A.Nested
{
    // Implementation of isNegative from A.Nested
public
    boolean isNegative(int x)
    {
        return x < 0 ? true : false;
    }

    // Implementation of print from inNested
public
    void print(String str)
    {
        System.out.println(str);
    }
}

public
class Main
{
public
    static void main(String[] args)
    {
        // Referral using fully qualified names
        A.Nested nes = new B();
        inNested ines = new B();

        // Testing the logic
        if (!nes.isNegative(10))
        {
            // Casting to B to use the print method not present in A.Nested
            ((B)nes).print("Positive");
        }

        if (ines.isNegative(-5))
        {
            ((B)ines).print("Negative.");
        }
    }
}