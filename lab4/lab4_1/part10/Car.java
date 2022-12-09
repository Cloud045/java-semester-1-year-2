package lab4.lab4_1.part10;

public class Car extends Transport {
    public enum Brand {
        Bugatti,
        Audi,
        Honda;
    }

    protected Brand brand;

    public Car(double generator, double speed, String color, Brand brand) {
        super(generator, speed, color);
        this.brand = brand;
    }

    @Override
    public double CostTrans(double time, double oilprice) {
        return generator * time * oilprice;
    }

    @Override
    public double TimeTrans(double distance) {
        return distance / speed;
    }

    @Override
    public String toString() {
        return "Car{" +
                "brand=" + brand +
                ", generator=" + generator +
                ", speed=" + speed +
                ", color='" + color + '\'' +
                '}';
    }
}
