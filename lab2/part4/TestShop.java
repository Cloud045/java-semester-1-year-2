package lab2.part4;

import java.util.Scanner;

interface Scan {
    shop Input();
}

public class TestShop {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        shop S = new shop();
        S = S.Input();
        S.showComputer();

        System.out.print("Name of new computer: ");
        String computername = input.next();
        S.AddComputer(computername);
        S.showComputer();

        System.out.print("Name of computer will be removed: ");
        computername = input.next();
        S.RemoveComputer(computername);
        S.showComputer();

        System.out.print("Name of computer want to find: ");
        computername = input.next();
        int check = S.FindComputer(computername);
        System.out.println(check);
        if (check == 0) System.out.println("Not Found!");
        else System.out.println(computername + " at index:" + check);
    }
}
