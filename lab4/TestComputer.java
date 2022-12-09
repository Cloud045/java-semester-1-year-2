package lab4;

public class TestComputer {


    public static void main(String[] args) {
        Processor i9 = new Processor(12, 24);
        Processor i7 = new Processor(9, 18);
        Processor i5 = new Processor(6, 12);
        Monitor Acer = new Monitor("1920x1080", 75, 22.4);
        Monitor Asus = new Monitor("4320x2440", 240, 35.6);
        Monitor Msi = new Monitor("2160x1440", 165, 40.3);
        Memory Samsung = new Memory(500);
        Memory Kingston = new Memory(256);
        Memory Concac = new Memory(1024);
        Computer computer1 = new Computer(Computer.Brands.Nasus, i9, Acer, Samsung);
        Computer computer2 = new Computer(Computer.Brands.Yasuo, i7, Asus, Concac);
        Computer computer3 = new Computer(Computer.Brands.Yone, i5, Msi, Kingston);

        System.out.println(computer1);
        System.out.println(computer2);
        System.out.println(computer3);
    }
}
