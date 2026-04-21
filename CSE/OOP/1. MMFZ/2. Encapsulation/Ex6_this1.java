// https://github.com/mdraihankabirsifat/Random
class Message {
    private String msg;
    public Message(String msg) {
        this.msg = msg;
    }
    public Message updateMessage(String msg) {
        this.msg = msg;
        return this;
    }
    public void displayMessage() {
        System.out.println("Message: " + this.msg);
    }
}

public class Ex6_this1 {
    public static void main(String[] args) {
        Message msg = new Message("Hello, World!");
        msg.displayMessage();
        msg = msg.updateMessage("New Message.");
        msg.displayMessage();
    }
}