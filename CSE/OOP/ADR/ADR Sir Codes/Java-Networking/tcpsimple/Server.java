import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    private ServerSocket serverSocket;
    private int clientCount = 0;

    Server() {
        try {
            serverSocket = new ServerSocket(44444);
            System.out.println("Server is waiting ... ");
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Server accepts a client ... ");
                serve(clientSocket);
            }
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Server error: " + e.getMessage());
        }
    }

    private void serve(Socket clientSocket) throws IOException, ClassNotFoundException {
        clientCount++;
        try (ObjectOutputStream oos = new ObjectOutputStream(clientSocket.getOutputStream());
             ObjectInputStream ois = new ObjectInputStream(clientSocket.getInputStream())) {
            System.out.println(ois.readObject() + "," + clientCount);
            oos.writeObject("Hello Client : " + clientCount);
        }
    }
    public static void main(String args[]) {
        new Server();
    }
}
