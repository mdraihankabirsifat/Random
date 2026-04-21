// Interface definition

public interface Ex14_Fly {

    // method declaration only
    public String fly();
}

// Dog class implementing Ex14_Fly
class Dog implements Ex14_Fly {

    public String fly() {
        return "I cannot fly.";
    }

    public String MakeSound() {
        return "I sound berk.";
    }
}

// Bird class implementing Ex14_Ex14_Fly
class Bird implements Ex14_Fly {

    public String fly() {
        return "I fly in the sky.";
    }

    public String MakeSound() {
        return "I sound chi-chi.";
    }
}

// Biman class implementing Ex14_Fly
class Biman implements Ex14_Fly {

    public String fly() {
        return "I fly too high in the sky.";
    }
}
