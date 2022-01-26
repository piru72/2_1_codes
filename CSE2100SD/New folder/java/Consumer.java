//package Project;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

// Inheritance Is used
 /*class SuperConsumer {
	Socket socket;
	BufferedReader br; // to
	PrintWriter out; // to write data

	public void startReading() {
		System.out.println("sending request to server");
	}
} */

public class Consumer extends SuperConsumer {

	// Socket socket;
	// BufferedReader br; // to
	// PrintWriter out; // to write data

	public Consumer() {
		try {
			System.out.println("sending request to server");
			socket = new Socket("127.0.0.1", 999); // ip address and port number
			System.out.println("connection done");

			// to read data
			br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			// socket.getInputStream will give data to InputStreamReader and change it to
			// character
			// then BufferedReader will handle it and we will read it by br variable

			// to write data or pass data-
			out = new PrintWriter(socket.getOutputStream());

			startReading();
			startWriting();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void startReading() {// it will continuously read our data

		Runnable r1 = () -> { // codes to read data

			System.out.println("reader started");

			while (true) {
				try {
					String msg = br.readLine(); // msg will be coming from client

					if (msg.equals("bye")) { // to stop reading
						System.out.println("server terminated the chat");
						break;
					}
					System.out.println("Server: " + msg);
				}

				catch (Exception e) {
					e.printStackTrace();
				}

			}
		};

		new Thread(r1).start(); // referring r1 to a new thread
	}

	public void startWriting() {// it will receive data from user and send it to client

		Runnable r2 = () -> { // codes to input data from user and then write/pass data to client
			System.out.println("writer started");
			while (true) {
				try {

					BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in)); // to get data from user

					String content = br1.readLine();
					out.println(content);
					out.flush();

				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		};
		new Thread(r2).start();

	}

	public static void main(String[] args) {
		System.out.println("consumer: ");
		new Consumer();

	}
}