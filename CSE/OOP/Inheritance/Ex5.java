// Abstract base class
abstract class Figure
{
    double dim1, dim2;

    // Constructor to initialize dimensions
    Figure(double a, double b)
    {
        dim1 = a;
        dim2 = b;
    }

    /** * Abstract Method:
     * Has no body and MUST be overridden by non-abstract subclasses.
     * Note: Constructors and static methods CANNOT be abstract.
     */
    abstract double area();
}

// Subclass implementing the abstract method
class Rectangle extends Figure
{
    Rectangle(double a, double b)
    {
        super(a, b); // Calling parent constructor
    }

    // Overriding the abstract method
    double area()
    {
        return dim1 * dim2;
    }
}

// Another subclass implementing the abstract method
class Triangle extends Figure
{
    Triangle(double a, double b)
    {
        super(a, b);
    }

    // Providing specific implementation for Triangle area
    double area()
    {
        return 0.5 * dim1 * dim2;
    }
}

public class FigureDemo
{
public
    static void main(String[] args)
    {
        Rectangle r = new Rectangle(4, 5);
        Triangle t = new Triangle(4, 3);

        /** * Abstract Class Reference:
         * You cannot do 'new Figure()', but you CAN create a
         * reference variable of type Figure to use polymorphism.
         */
        Figure figref;

        figref = r;
        System.out.println("Area: " + figref.area()); // Output: 20.0

        figref = t;
        System.out.println("Area: " + figref.area()); // Output: 6.0
    }
}