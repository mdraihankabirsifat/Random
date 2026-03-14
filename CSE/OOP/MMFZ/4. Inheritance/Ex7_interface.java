// Definition of the Interface
interface InterfaceDemo
{
    // Interface constant (implicitly public static final)
public
    double PI = 3.14159;

    // Abstract method (must be implemented by subclasses)
public
    void volume();

    // Default method (provides a default implementation)
    default double circleArea(double radius)
    {
        System.out.println(getName());
        return PI * radius * radius;
    }

    // Private method (used within the interface)
private
    String getName()
    {
        return "Area is calculated using default method.";
    }
}

// Class implementing the interface
class Cylindar implements InterfaceDemo
{
private
    String name;
private
    double height;
private
    double radius;

    Cylindar(double nh, double nr)
    {
        height = nh;
        radius = nr;
    }

public
    void volume()
    {
        double vol = height * circleArea(radius);
        print(vol);
    }

private
    void print(double vol)
    {
        System.out.println(name + " Volume: " + vol);
    }
}

// Another class implementing the same interface
class Cone implements InterfaceDemo
{
private
    String name;
private
    double height;
private
    double radius;

    Cone(double nh, double nr)
    {
        height = nh;
        radius = nr;
    }

public
    void volume()
    {
        double vol = height * circleArea(radius) / 3;
        System.out.println(name + " Volume: " + vol);
    }
}

public class Main
{
public
    static void main(String[] args)
    {
        Cylindar cylindar = new Cylindar(5.6, 4.2);
        Cone cone = new Cone(5.6, InterfaceDemo.PI);

        cylindar.volume();
        cone.volume();
    }
}