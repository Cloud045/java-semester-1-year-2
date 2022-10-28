package lab2.part6;

import java.util.Scanner;

public class TestCircle {
    public static void main(String[] args) {
        circle C = new circle(4.6, 5.3, 8.1, "red");
        System.out.println("Perimeter: " + C.getPerimeter());
        System.out.print("New radius: ");
        Scanner input = new Scanner(System.in);
        double r = input.nextDouble();
        C.setR(r);
        System.out.println("New perimeter: " + C.getPerimeter());
        System.out.println(C);
    }
}
