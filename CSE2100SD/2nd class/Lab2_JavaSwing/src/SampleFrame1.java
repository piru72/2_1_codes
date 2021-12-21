
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Medul
 */
public class SampleFrame1 extends JFrame{
    JTextField jtf = new JTextField();
    
    public class ActionListenerExample implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent ae) {
            System.out.println("Hello World");
            jtf.setText("Hello World");
        }

    }
    
    SampleFrame1(){
        JButton button = new JButton("Click");
        // (x, y, width, height)
        button.setBounds(150, 50, 100, 40);
        add(button);
        
        button.addActionListener(new ActionListenerExample());
        
        
        jtf.setBounds(130, 100, 150, 40);
        add(jtf);
        
        setSize(400, 400);
        setLayout(null);
        setVisible(true);
        
    }
    
    public static void main(String[] args) {
        SampleFrame1 frame = new SampleFrame1();
        frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
    }
}
