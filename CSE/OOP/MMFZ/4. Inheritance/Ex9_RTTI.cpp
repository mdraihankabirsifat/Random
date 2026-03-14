#include <iostream>
#include <typeinfo> // Required for using typeid and type_info
using namespace std;

// Abstract Base Class
class Animal
{
public:
    // Virtual function ensures Animal is a polymorphic class, which RTTI requires
    virtual void sound() = 0;
};

class Dog : public Animal
{
public:
    void sound()
    {
        cout << "Bark" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound()
    {
        cout << "Meow" << endl;
    }
};

int main()
{
    Dog *dog = new Dog();
    Cat *cat = new Cat();
    double length = 25.5;
    int num = 10;
    Animal *animal;

    // Identifying primitive types
    const type_info &type_num = typeid(num);
    cout << "Type(num): " << type_num.name() << endl; // Output: i (integer)

    // Identifying pointer types vs. the actual objects they point to
    cout << "Type(dog): " << typeid(dog).name() << endl;   // Output: P3Dog (Pointer to Dog)
    cout << "Type(*dog): " << typeid(*dog).name() << endl; // Output: 3Dog (Dog object)
    cout << "Type(cat): " << typeid(cat).name() << endl;   // Output: P3Cat (Pointer to Cat)

    cout << "Type(length): " << typeid(length).name() << endl; // Output: d (double)

    // RTTI with Polymorphic Base Pointers
    animal = dog;
    // animal (pointer type) remains Animal, but *animal (object type) becomes Dog
    cout << "Type(animal): " << typeid(animal).name() << endl;   // Output: P6Animal
    cout << "Type(*animal): " << typeid(*animal).name() << endl; // Output: 3Dog

    animal = cat;
    cout << "Type(animal): " << typeid(animal).name() << endl;   // Output: P6Animal
    cout << "Type(*animal): " << typeid(*animal).name() << endl; // Output: 3Cat

    // Type identification of expressions
    cout << "Type(length+num): " << typeid(length + num).name() << endl; // Output: d (result is double)

    return 0;
}