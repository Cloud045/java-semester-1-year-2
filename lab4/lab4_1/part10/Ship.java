package lab4.lab4_1.part10;

public class Ship extends Transport {
    protected int weight;

    public Ship(double generator, double speed, String color, int weight) {
        super(generator, speed, color);
        this.weight = weight;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
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
        return "Ship{" +
                ", generator=" + generator +
                ", weight=" + weight +
                ", speed=" + speed +
                ", color='" + color + '\'' +
                '}';
    }
}
