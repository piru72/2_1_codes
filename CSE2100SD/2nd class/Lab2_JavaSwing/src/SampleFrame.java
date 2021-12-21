
import javax.swing.JButton;
import javax.swing.JFrame;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Medul
 */
public class SampleFrame {
    
    public static void main(String[] args) {
        JFrame frame = new JFrame("My Frame Frame");
        frame.setSize(400, 400);
        frame.setLayout(null);
        frame.setVisible(true);
        
        JButton button = new JButton("Click");
        // (x, y, width, height)
        button.setBounds(150, 50, 100, 40);
        frame.add(button);
        
        frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
        
    }
}
