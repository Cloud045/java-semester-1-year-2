package lab1.part4;

import java.util.Scanner;

public class part4 {
    public static void main(String[] args) {
        Scanner input= new Scanner(System.in);
        System.out.print("Input n: ");
        int n = input.nextInt();
        System.out.print("Input value of " + n + " numbers : ");
        int sum=0,min=Integer.MAX_VALUE,max=0;
        while(n>0){
            n--;
            int m = input.nextInt();
            sum+=m;
            max=Math.max(m,max);
            min=Math.min(m,min);
        }
        System.out.println("Sum= "+sum);
        System.out.println("Max= "+max);
        System.out.println("Min= "+min);
    }
}
