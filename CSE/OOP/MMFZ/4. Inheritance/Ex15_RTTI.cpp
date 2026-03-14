#include <iostream>
#include <typeinfo>
using namespace std;

class Animal
{
public:
    virtual void sound() = 0;
};

class Dog : public Animal
{
    void sound()
    {
        cout << "Bark" << endl;
    }
};

class Cat : public Animal
{
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

    const type_info &type_num = typeid(num);
    cout << "Type(num): " << type_num.name() << endl;
    cout << "Type(dog): " << typeid(dog).name() << endl;
    cout << "Type(*dog): " << typeid(*dog).name() << endl;
    cout << "Type(cat): " << typeid(cat).name() << endl;
    cout << "Type(length): " << typeid(length).name() << endl;

    animal = dog;
    cout << "Type(animal): " << typeid(animal).name() << endl;
    cout << "Type(*animal): " << typeid(*animal).name() << endl;

    animal = cat;
    cout << "Type(animal): " << typeid(animal).name() << endl;
    cout << "Type(*animal): " << typeid(*animal).name() << endl;

    cout << "Type(length+num): " << typeid(length + num).name() << endl;
    return 0;
}

/*
Key Notes:

1. typeid gives runtime type information.

2. typeid(pointer) and typeid(*pointer) can differ.

3. For polymorphic base pointer, typeid(*pointer) shows actual object type.
*/