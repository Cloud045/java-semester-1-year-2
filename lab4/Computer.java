package lab4;

public class Computer {
    public enum Brands {
        Nasus,
        Yasuo,
        Yone;
    }

    public Processor processor;
    private Monitor monitor;
    private Memory memory;

    private Brands brand;

    public Computer(Brands brand, Processor processor, Monitor monitor, Memory memory) {
        this.brand = brand;
        this.processor = processor;
        this.memory = memory;
        this.monitor = monitor;
    }

    @Override
    public String toString() {
        return "Computer{" +
                "processor=" + processor +
                ", monitor=" + monitor +
                ", memory=" + memory +
                ", brand=" + brand +
                '}';
    }
}
