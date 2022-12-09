package lab4.lab4_1.part10;

public class Plane extends Transport {
    public enum Brand {
        Aeroflot,
        VietnamAirline,
        VietJet;
    }

    protected int capacity;
    protected Brand brand;

    public Plane(double generator, double speed, String color, int capacity, Brand brand) {
        super(generator, speed, color);
        this.capacity = capacity;
        this.brand = brand;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
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
        return "Plane{" +
                "brand=" + brand +
                ", capacity=" + capacity +
                ", generator=" + generator +
                ", speed=" + speed +
                ", color='" + color + '\'' +
                '}';
    }
}
