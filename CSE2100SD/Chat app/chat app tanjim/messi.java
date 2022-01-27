
import java.awt.Color;
import java.awt.Font;
import java.awt.Image;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

public class server1 extends SuperServer1 implements msgReadingPlace {
	/**
	 *
	 */
	private static final long serialVersionUID = 1398116078808624864L;

	// constructor to initialize server immediately
	public server1() {
		try {

			if (!file.exists()) {
				try {
					file.createNewFile();
				} catch (Exception e) {
					// TODO: handle exception
				}
			}

			createGUI();
			handleEvent();

			server = new ServerSocket(999); // to use this particular this as on port number 999, only the server will
											// be running

			System.out.println("Server is ready to accept connection");
			System.out.println("waiting...");

			// server.accept(); // when client will send request, this will enable server to
			// accept the request
			socket = server.accept();

			// to read data
			br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			// socket.getInputStream will give data to InputStreamReader and change it to
			// character
			// then BufferedReader will handle it and we will read it by br variable

			// to write data or pass data-
			out = new PrintWriter(socket.getOutputStream());

			startReading();

		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	// Here we apply Polymorphism by overriding welcomeMessage() method
	public void welcomeMessage() {
		JOptionPane.showMessageDialog(null, "Welcome To Server Message Area", "Confirmation",
				JOptionPane.WARNING_MESSAGE);
	}

	public void createGUI() {

		// for images

		pl1 = new JPanel();
		pl1.setLayout(null);
		pl1.setBackground(Color.red);
		pl1.setBounds(0, 0, 450, 60);
		add(pl1);

		image = new ImageIcon(getClass().getResource("messi.jpg"));

		// we can not pass any image directly to the frame. so we have to do it by using
		// label

		Image i1 = image.getImage().getScaledInstance(100, 100, Image.SCALE_DEFAULT);

		// image2 wont directly goes to JLable so we have to convert it again into
		// imageIcon

		ImageIcon ig1 = new ImageIcon(i1);

		lb1 = new JLabel(ig1);// icon

		lb1.setBounds(0, 0, 100, 100);// icon
		pl1.add(lb1);// icon

		// for person name
		JLabel lb3 = new JLabel("Messi");
		lb3.setBounds(115, 15, 100, 20);
		lb3.setFont(new Font("SAN_SERIF", Font.BOLD, 20));
		lb3.setForeground(Color.white);
		pl1.add(lb3);

		// text area

		messageArea.setBackground(Color.WHITE);
		messageArea.setBounds(0, 60, 450, 450);
		messageArea.setFont(new Font("SAN_SERIF", Font.BOLD, 15));
		messageArea.setForeground(Color.BLACK);
		messageArea.setEditable(false);
		messageArea.setLineWrap(true);
		messageArea.setWrapStyleWord(true);

		add(messageArea);

		// adding scroll bar

		JScrollPane jScrollPane = new JScrollPane(messageArea);
		jScrollPane.setBounds(0, 60, 450, 440);
		getContentPane().add(jScrollPane);
		setLocationRelativeTo(null);

		// text field

		messageInput.setBackground(Color.BLACK);
		messageInput.setBounds(0, 500, 450, 40);
		messageInput.setFont(new Font("SAN_SERIF", Font.BOLD, 15));
		messageInput.setForeground(Color.WHITE);

		add(messageInput);

		// full plate

		getContentPane().setBackground(Color.YELLOW);

		setLayout(null);

		setSize(465, 580);
		setLocation(500, 60);

		setUndecorated(false);

		setVisible(true);

	}

	public void handleEvent() {

		messageInput.addKeyListener(new KeyListener() {

			@Override
			public void keyTyped(KeyEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void keyPressed(KeyEvent e) {
				// TODO Auto-generated method stub
				int key = e.getKeyCode();

				// writing files
				if (key == 10) {
					try {

						FileWriter fw = new FileWriter(file, true);
						BufferedWriter bw = new BufferedWriter(fw);
						messageInput.write(bw);
						bw.newLine();
						bw.close();

					}

					catch (Exception ex) {
						System.out.println("File is not reading or writing");
					}
				}

			}

			@Override
			public void keyReleased(KeyEvent e) {

				// TODO Auto-generated method stub

				if (e.getKeyCode() == 10) {

					String contentToSend = messageInput.getText();

					messageArea.append("Me : " + contentToSend + "\n");
					out.println(contentToSend);
					out.flush();
					messageInput.setText("");

				}
			}

		});
	}

	// we will read it by this method
	public void startReading() {// it will continuously read our data

		// codes to read data

		System.out.println("reader started");

		try {

			while (true) {

				String msg = br.readLine(); // msg will be coming from client

				if (msg.equalsIgnoreCase("Bye")) { // to stop reading
					JOptionPane.showMessageDialog(null, "Server is terminated");
					messageInput.setEnabled(false);
					socket.close();
					break;
				}
				messageArea.append("Consumer: " + msg + "\n");
			}
		} catch (Exception e) {
			System.out.println("Connection is closed");
		}

	}

	public static void main(String[] args) {
		System.out.println("server:  ");
		new server1();// to run server immediately in the constructor

	}
}