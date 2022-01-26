package Project;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

interface Readability {
	public void startReading();
}

class server implements Readability {
	ServerSocket server;
	Socket socket;
	// for reading and writing data
	BufferedReader br; // to
	PrintWriter out; // to write data

	// constructor to initialise server immidiately
	public server() {
		try {
			server = new ServerSocket(999); // to use this particular this as on port number 999, only the server will
											// be running

			System.out.println("Server is ready to accept connection");
			System.out.println("waiting...");

			// server.accept(); // when client will send request, this will enable server to
			// accept the request
			socket = server.accept();
			// System.out.println("accepted");

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

	// we will use this two method to read and write data simultaniously--(multi
	// threading)
	// we will read it by this method
	public void startReading() {// it will continuously read our data

		Runnable r1 = () -> { // codes to read data

			System.out.println("reader started");

			while (true) {
				try {
					String msg = br.readLine(); // msg will be coming from client

					if (msg.equals("bye")) { // to stop reading
						System.out.println("client said bye");
						socket.close();
						break;
					}
					System.out.println("Consumer: " + msg);
				}

				catch (Exception e) { // ki dhoroner exception hoite pare
					e.printStackTrace();
				}

			}
		};

		new Thread(r1).start(); // referring r1 to a new thread
	}

	// we will write it by this method
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
		System.out.println("server:  ");
		new server();// to run server immdiately in the constructor
	}
}