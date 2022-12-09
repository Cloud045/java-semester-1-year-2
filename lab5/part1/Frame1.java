package lab5.part1;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class Frame1 {
    private int acscore = 0;
    private int realscore = 0;

    private String result = "0 X 0";

    private String LastSoccer = "N/A";

    private String Winner = "DRAW";

    public void Display() {

        JFrame frame = new JFrame("ACMILAN x REALMADRID");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1000, 800);

        JPanel panel1 = new JPanel();
        JPanel panel2 = new JPanel();

        panel1.setBackground(Color.GRAY);

        panel1.setPreferredSize(new Dimension(1000, 800));
        JButton button1 = new JButton("AC MILAN");
        JButton button2 = new JButton("REAL MADRID");
        JLabel label1 = new JLabel("Result: " + result, JLabel.LEFT);
        JLabel label2 = new JLabel("Last Soccer: " + LastSoccer, JLabel.CENTER);
        JLabel label3 = new JLabel("Winner: " + Winner, JLabel.CENTER);
        panel1.add(button1);
        panel1.add(button2);
        panel1.add(label1);
        panel1.add(label2);
        panel1.add(label3);

        frame.getContentPane().add(panel1);

        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                acscore++;
                result = acscore + " x " + realscore;
                LastSoccer = "AC MILAN";
                if (acscore > realscore) Winner = "AC MILAN";
                else if (realscore > acscore) Winner = "REAL MADRID";
                else Winner = "DRAW";
                frame.dispose();
                Display();
            }
        });
        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                realscore++;
                result = acscore + " x " + realscore;
                LastSoccer = "REAL MADRID";
                if (acscore > realscore) Winner = "AC MILAN";
                else if (realscore > acscore) Winner = "REAL MADRID";
                else Winner = "DRAW";
                frame.dispose();
                Display();
            }
        });


        frame.setLocationRelativeTo(null);
        frame.pack();
        frame.setVisible(true);
    }

    public Frame1() {
        Display();
    }

    public static void main(String[] args) {
        new Frame1();
    }
}