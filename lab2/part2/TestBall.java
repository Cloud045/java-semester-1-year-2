package lab2.part2;

import java.lang.*;
import java.util.Scanner;

public class TestBall {
    public static void main(String[] args) {
        ball b1 = new ball();
        ball b2 = new ball(9.8, 5.6);
        System.out.println(b1);
        System.out.println(b2);
        Scanner input = new Scanner(System.in);
        System.out.println("Введите X: ");
        double x = input.nextDouble();
        System.out.println("Введите Y: ");
        double y = input.nextDouble();
        b1.setXY(x, y);
        System.out.println("Local ball b1: ");
        System.out.println("X: " + b1.getX());
        System.out.println("Y: " + b1.getY());

        System.out.println("Введите XDisp: ");
        double xdisp = input.nextDouble();
        System.out.println("Введите YDisp: ");
        double ydisp = input.nextDouble();
        b1.move(xdisp, ydisp);
        System.out.println("Local ball b1 after move: ");
        System.out.println("X: " + b1.getX());
        System.out.println("Y: " + b1.getY());
    }
}
