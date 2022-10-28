package lab2.part5;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class TestDog {
    private dog[] D;
    static public int numbers;

    public void addDog() {
        dog dnew = new dog();
        D = Arrays.copyOf(D, numbers + 1);
        D[numbers] = dnew;
        numbers++;
    }

    public void addDog(String name, int age) {
        dog dnew = new dog(name, age);
        D = Arrays.copyOf(D, numbers + 1);
        D[numbers] = dnew;
        numbers++;
    }

    public void resize(int size) {
        D = new dog[size];
    }

    public void showAllDog() {
        for (int i = 0; i < numbers; ++i) {
            System.out.println(i + ". " + D[i]);
        }
    }

    public static void main(String[] args) {
        System.out.print("Numbers of dog: ");
        Scanner input = new Scanner(System.in);
        numbers = input.nextInt();
        TestDog file = new TestDog();
        file.resize(numbers);
        int n = numbers;
        numbers = 0;
        for (int i = 0; i < n; ++i) {
            System.out.println("Dog " + (i + 1) + ":");
            System.out.print("\tname: ");
            String name = input.next();
            System.out.print("\tage: ");
            int age = input.nextInt();
            file.addDog(name, age);
        }
        file.showAllDog();
        System.out.println("Do you want to add 1 dog to list?(yes/no)");
        String check = input.next();
        if (check.equals("yes")) {
            file.addDog();
            file.showAllDog();
        } else return;
    }
}
