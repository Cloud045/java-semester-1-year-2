package lab5.part3;


import javax.swing.JFrame;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

class Picture {
    public static void main(String args[]) {
        JFrame frame = new JFrame();
        ImageIcon icon = new ImageIcon("src/lab5/part3/2021-11-17.png");
        JLabel label = new JLabel(icon);
        frame.add(label);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //frame.setLocationRelativeTo(null);
        frame.pack();
        frame.setVisible(true);
    }
}