package lab5.part4;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Animations extends JPanel {

    Image img = new ImageIcon("src/lab5/part4/Picture/zYGW3rtFhpE.jpg").getImage();

    public static void main(String[] args) {
        JFrame fr = new JFrame();
        fr.setSize(500, 500);
        fr.setLayout(null);
        fr.setVisible(true);

        Animations m = new Animations();
        m.setBounds(100, 100, 500, 500);
        fr.add(m);
        fr.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        fr.setVisible(true);
    }

    public void paintComponent(Graphics g) {
        g.drawImage(img, 0, 0, null);
    }
}