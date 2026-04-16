// Static Method in Interface

interface MyIFStatic {

    int getNumber();

    default String getString() {
        return "Default String";
    }
// default can be called through implemented class but static can't

    static int getDefaultNumber() {
        return 0;
    }

}

public class Ex9_StaticInterfaceMethod {

    public static void main(String[] args) {

        System.out.println(MyIFStatic.getDefaultNumber());

    }
}

/*
Key Notes
---------
Static interface methods
are not inherited.

Called using:
InterfaceName.method()
 */
