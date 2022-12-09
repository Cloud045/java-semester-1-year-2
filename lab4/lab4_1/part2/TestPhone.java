package lab4.lab4_1.part2;

public class TestPhone {
    public static void main(String[] args) {
        Phone Iphone14Promax = new Phone(123456, "IPHONE", 780);
        Phone SamsungJFold4 = new Phone(773800, "SAMSUNG", 700);
        Phone XiaomiNote3 = new Phone(974502, "XIAOMI", 920);
        System.out.println(Iphone14Promax);
        System.out.println(SamsungJFold4);
        System.out.println(XiaomiNote3);
        Iphone14Promax.receiveCall("SamsungJFold4");
        int num1 = Iphone14Promax.getNumber();
        int num2 = SamsungJFold4.getNumber();
        int num3 = XiaomiNote3.getNumber();
        System.out.println(num1);
        System.out.println(num2);
        System.out.println(num3);
        Iphone14Promax.receiveCall("SamsungJFold4", 773800);
        XiaomiNote3.sendMessage(123456, 773800, 986347);
    }
}
