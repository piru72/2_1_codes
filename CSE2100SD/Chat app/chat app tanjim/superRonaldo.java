
import java.awt.Font;
import java.io.BufferedReader;
import java.io.File;
import java.io.PrintWriter;
import java.net.Socket;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class SuperConsumer1 extends JFrame {
	String contentToSend;

	File file = new File("consumerFile.txt");
	/*
	 * if (!file.exists()) { try { file.createNewFile(); } catch (Exception e) {
	 * //TODO: handle exception }
	 * 
	 * }
	 */

	private static final long serialVersionUID = 6246079836240865409L;
	Socket socket;
	BufferedReader br; // to
	PrintWriter out; // to write data

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
