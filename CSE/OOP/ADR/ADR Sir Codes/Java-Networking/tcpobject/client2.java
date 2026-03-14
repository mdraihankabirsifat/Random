//package tcpobject;

import java.net.Socket;
import java.util.Scanner;
import util.SocketWrapper;

public class client2 {

    private SocketWrapper socketWrapper;

    client2(String serverAddress, int port) {
        try {
            Socket socket = new Socket(serverAddress, port);
            socketWrapper = new SocketWrapper(socket);
            System.out.println("Connected to server.");
        } catch (Exception e) {
            System.out.println("Client starts: " + e);
        }
    }

    public void start() {
        try {
            Scanner scanner = new Scanner(System.in);

            System.out.print("Enter first number: ");
            int a = scanner.nextInt();

            System.out.print("Enter second number: ");
            int b = scanner.nextInt();

            // Send two integers to server
            socketWrapper.write(a);
            socketWrapper.write(b);

            // Receive result from server
            Object response = socketWrapper.read();

            System.out.println("Number of prime numbers between given range: " + response);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        client2 client = new client2("localhost", 44444);
        client.start();
    }
}