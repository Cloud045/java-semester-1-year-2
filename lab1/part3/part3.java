package lab1.part3;

public class part3 {
    public static void main(String[] args) {
        int sum=0;
        int[] a = {1,2,3,4,5,6,7,8,9,10};
        for(int i=0;i<10;++i) {
            sum+=a[i];
        }
        System.out.println("Sum= "+sum);
        System.out.println("Arg= "+(float)sum/10);
    }
}
