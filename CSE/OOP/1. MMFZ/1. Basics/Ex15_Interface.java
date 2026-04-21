// https://github.com/mdraihankabirsifat/Random
// Main class to demonstrate interface use

public class Ex15_Interface {

    public static void main(String[] args) {

        Ex14_Fly doggy = new Dog();
        Bird sweety = new Bird();
        Ex14_Fly gogon = new Biman();

        System.out.println("I am a dog." + doggy.fly() + ((Dog) doggy).MakeSound());
        System.out.println("I am a bird." + sweety.fly() + sweety.MakeSound());
        System.out.println("I am a Biman." + gogon.fly());
    }
}

/*
Key Notes:
1. Interface → contains only method declarations.
2. Classes implement interface using "implements".
3. Interface enables abstraction and polymorphism.
4. Multiple classes can implement the same interface.
*/
