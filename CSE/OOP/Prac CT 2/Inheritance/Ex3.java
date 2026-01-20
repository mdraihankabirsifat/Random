class Father
{
private
    String name;
public
    int age;

    Father(String fName)
    {
        name = fName;
        age = 60;
    }

public
    void show()
    {
        System.out.println("Father: " + name);
    }
}

class Son extends Father
{
private
    String name;
public
    int age;

    Son(String sName, String fName)
    {
        // Calls the base class constructor
        super(fName);
        age = 20;
        name = sName;
    }

    @Override public void show()
    {
        // Calls the father's show() method
        super.show();
        System.out.println("Son: " + name);
    }

public
    void showAge()
    {
        System.out.println("Son's Age: " + age);
    }
}

public class Main
{
public
    static void main(String[] args)
    {
        Father father = new Father("Rashid");
        // Polymorphic reference: Base class variable, Derived class object
        Father son = new Son("Habib", "Jashim");

        father.show(); // Output: Father: Rashid

        /** * Dynamic Method Dispatch:
         * Even though 'son' is a Father reference, it calls Son's show()
         * because the actual object is a Son.
         */
        son.show();

        /** * Casting:
         * son.showAge() would fail because showAge() isn't in Father class.
         * Explicit casting to Son is required to access Son-specific methods.
         */
        ((Son)son).showAge();

        // Fields (variables) are NOT overridden; they are hidden.
        // Accessing son.age refers to Father's age (60), not Son's age (20).
        System.out.println(son.age);

        // Reassigning reference
        father = son;
        father.show();
    }
}