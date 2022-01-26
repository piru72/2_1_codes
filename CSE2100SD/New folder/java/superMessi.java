
import java.awt.Font;
import java.io.BufferedReader;
import java.io.File;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class SuperServer1 extends JFrame {
	File file = new File("serverFile.txt");
	/**
	 *
	 */
	private static final long serialVersionUID = 1L;
	ServerSocket server;
	Socket socket;
	// for reading and writing data
	BufferedReader br; // to
	PrintWriter out, output;

	// declaring components

	public JTextArea messageArea = new JTextArea();
	public JTextField messageInput = new JTextField();

	// font
	public Font font = new Font("Roboto", Font.BOLD, 20);

	// for images

	public JPanel pl1;
	public JLabel lb1, lb2, lb3, lb4, lb5;
	public ImageIcon image, image1, image2, ig1, ig2;

	public void welcomeMessage() {
		System.out.println("Welcome Message");
	}
}