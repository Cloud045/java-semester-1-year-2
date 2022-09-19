package lab1.part7;

import java.util.Scanner;

public class part7 {
    public static int getFactorial(int f) {
        if (f <= 1) {
            return 1;
        }
        else {
            return f * getFactorial(f - 1);
        }
    }
    public static void main(String[] args) {
        Scanner input= new Scanner(System.in);
        System.out.print("Input n: ");
        int n = input.nextInt();
        int calc1=getFactorial(n);
        System.out.println("F("+n+")= "+calc1);
        int calc2=1;
        for(int i=1;i<=n;++i){
            calc2*=i;
        }
        if(calc1==calc2) System.out.println("Check pass! True Answer!");
        else System.out.println("Check Fail! Wrong Answer!");
    }
}
