class NewThread2 extends Thread {
	NewThread2() {
		super("ExtendsThread");
		start();
	}

	// This is the entry point for the thread.
	public void run() {
		try {
			for (int i = 5; i > 0; i--) {
				System.out.println("Child Thread: " + i);
				Thread.sleep(500);
			}
		} catch (InterruptedException e) {
			System.out.println("Child interrupted.");
		}
		System.out.println("Exiting child thread.");
	}
}

public class Extending_Thread {
	public static void main(String[] args) {
		new NewThread2();
	}
}