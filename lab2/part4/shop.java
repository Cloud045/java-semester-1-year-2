package lab2.part4;

import java.util.Scanner;
import java.util.Vector;

public class shop implements Scan {
    private Vector<String> Computer;
    private int NumbersOfComputer;

    public shop() {
        this.Computer = new Vector<>();
        NumbersOfComputer = 0;
    }

    public void showComputer() {
        for (int i = 0; i < NumbersOfComputer; ++i) {
            System.out.println("Computer[" + (i + 1) + "]: " + Computer.get(i));
        }
    }

    public int getNumbersOfComputer() {
        return NumbersOfComputer;
    }

    public void AddComputer(String computer) {
        this.NumbersOfComputer++;
        Computer.addElement(computer);
    }

    public void RemoveComputer(String computer) {
        for (int i = 0; i < NumbersOfComputer; ++i) {
            if (Computer.get(i).equals(computer)) {
                Computer.removeElementAt(i);
                NumbersOfComputer--;
                break;
            }
        }
    }

    public int FindComputer(String computer) {
        for (int i = 0; i < NumbersOfComputer; ++i) {
            if (Computer.get(i).equals(computer))
                return (i + 1);
        }
        return 0;
    }

    public shop Input() {
        shop Shop = new shop();
        System.out.print("Введите количество компьютеров : ");
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; ++i) {
            String m = input.next();
            Shop.AddComputer(m);
        }
        return Shop;
    }
}
