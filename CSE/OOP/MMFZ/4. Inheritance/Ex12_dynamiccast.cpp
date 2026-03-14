#include <iostream>
using namespace std;

class Animal
{
public:
    // virtual function makes the class polymorphic, which is required for dynamic_cast
    virtual void print()
    {
        cout << "Animal" << endl;
    }
};

class Dog : public Animal
{
public:
    void print()
    {
        cout << "Dog" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound()
    {
        cout << "Cat" << endl;
    }
};

class myClass
{
};

int main()
{
    Animal *animal = new Animal;
    Dog *dog = new Dog;
    Cat *cat = new Cat;

    animal->print(); // Output: Animal

    // Upcasting: Converting Dog* to Animal* (Always safe)
    animal = dynamic_cast<Animal *>(dog);
    animal->print(); // Output: Dog

    // Upcasting: Converting Cat* to Animal* (Always safe)
    animal = dynamic_cast<Animal *>(cat);
    animal->print(); // Output: Cat

    /**
     * Downcasting: Converting Animal* back to Dog*
     * This fails because 'animal' currently points to a 'Cat' object.
     * dynamic_cast returns NULL if the pointer cast fails.
     */
    Dog *d = dynamic_cast<Dog *>(animal);
    if (d == nullptr)
    {
        cout << "Conversion failed" << endl; // This will execute
    }
    else
    {
        d->print();
    }

    /**
     * Casting to an unrelated class:
     * This will result in a compile-time error or return NULL at run-time
     * because there is no inheritance relationship.
     */
    myClass *x = dynamic_cast<myClass *>(animal);

    return 0;
}