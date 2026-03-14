// Abstract base class
abstract class Animal
{
    abstract public void sound();
}

// Concrete subclass 1
class Dog extends Animal
{
public
    void sound()
    {
        System.out.println("Bark");
    }
}

// Concrete subclass 2
class Cat extends Animal
{
public
    void sound()
    {
        System.out.println("Meow");
    }
}

// Helper class to print type information
class PrintType
{
public
    void printType(Object ob)
    {
        /**
         * getClass(): A method of the Object class that returns
         * the runtime class of the object.
         */
        System.out.println(ob.getClass());
    }
}

public class Main
{
public
    static void main(String[] args)
    {
        Dog dog = new Dog();
        Cat cat = new Cat();
        Double length = 25.5; // Wrapper class object
        Integer num = 10;     // Wrapper class object
        PrintType pt = new PrintType();

        /**
         * instanceof Operator: Returns true if the object is an
         * instance of the specified class or subclass.
         */
        if (dog instanceof Dog)
        {
            System.out.println("Yes, Dog.");
        }

        // Identifying types through the helper method
        pt.printType(dog); // Output: class Dog
        pt.printType(cat); // Output: class Cat

        // RTTI with polymorphic references
        Animal animal = dog;
        pt.printType(animal); // Output: class Dog (Identifies actual object)

        animal = cat;
        pt.printType(animal); // Output: class Cat

        // Identifying types for generic Object references
        Object ob = length;
        pt.printType(ob); // Output: class java.lang.Double

        ob = num;
        pt.printType(ob); // Output: class java.lang.Integer

        ob = dog;
        pt.printType(ob); // Output: class Dog
    }
}