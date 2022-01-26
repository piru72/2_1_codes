

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
import java.net.Socket;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

//Inheritance
public class consumer1 extends SuperConsumer1 implements msgReadingPlace {

	private static final long serialVersionUID = -4045193717509406983L;

	public consumer1() {

		try {
			if (!file.exists()) {
				try {
					file.createNewFile();
				} catch (Exception e) {

				}
			}

			System.out.println("Sending request to server");
			socket = new Socket("127.0.0.1", 999); // ip address and port number
			System.out.println("connection done");

			br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			/*
			 * socket.getInputStream will give data to InputStreamReader and change it to
			 * character // then BufferedReader will handle it and we will read it by br
			 * variable
			 */

			// to write data or pass data-
			out = new PrintWriter(socket.getOutputStream());

			createGUI();
			handleEvent();

			startReading();

		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	// Here we apply Polymorphism by overriding welcomeMessage() method
	public void welcomeMessage() {
		JOptionPane.showMessageDialog(null, "Welcome To Consumer Message Area", "Confirmation",
				JOptionPane.WARNING_MESSAGE);
	}

	public void createGUI() {
		// for images

		pl1 = new JPanel();
		pl1.setLayout(null);
		pl1.setBackground(Color.red);
		pl1.setBounds(0, 0, 450, 60);
		add(pl1);

		// consumer Rronaldo
		image = new ImageIcon(getClass().getResource("ronaldo.jpg"));

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
		JLabel lb3 = new JLabel("Ronaldo");
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
						// TODO: handle exception
					}
				}

				// TODO Auto-generated method stub

			}

			@Override
			public void keyReleased(KeyEvent e) {

				// TODO Auto-generated method stub

				// appending to text area and sending to another class
				if (e.getKeyCode() == 10) {

					contentToSend = messageInput.getText();

					messageArea.append("Me : " + contentToSend + "\n");
					out.println(contentToSend);

					out.flush();
					messageInput.setText("");

				}

			}

		});
	}

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
				messageArea.append("Server: " + msg + "\n");

			}
		} catch (Exception e) {
			System.out.println("Connection is closed");
		}

	}

	public static void main(String[] args) throws Exception {
		System.out.println("consumer: ");

		new consumer1();

	}
}