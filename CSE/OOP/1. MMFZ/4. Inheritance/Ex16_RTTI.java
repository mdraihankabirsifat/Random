// https://github.com/mdraihankabirsifat/Random

abstract class Animal {

    abstract public void sound();
}

class Dog extends Animal {

    public void sound() {
        System.out.println("Bark");
    }
}

class Cat extends Animal {

    public void sound() {
        System.out.println("Meow");
    }
}

class PrintType {

    public void printType(Object ob) {
        System.out.println(ob.getClass()); // runtime class
    }
}

public class Ex16_RTTI {

    public static void main(String[] args) {
        Dog dog = new Dog();
        Cat cat = new Cat();
        Double length = 25.5;
        Integer num = 10;
        PrintType pt = new PrintType();

        if (dog instanceof Dog) {
            System.out.println("Yes, Dog.");
        }

        pt.printType(dog);
        pt.printType(cat);

        Animal animal = dog;
        pt.printType(animal);

        animal = cat;
        pt.printType(animal);

        Object ob = length; //class java.lang.Double
        pt.printType(ob);

        ob = num;
        pt.printType(ob);

        ob = dog;
        pt.printType(ob);
    }
}

/*
Key Notes:

1. instanceof checks object type.

2. getClass() prints actual runtime class.

3. Base reference still keeps actual object type at runtime.
*/
