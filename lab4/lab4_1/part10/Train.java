package lab4.lab4_1.part10;

public class Train extends Transport {
    protected int railtruck;

    public Train(double generator, double speed, String color, int railtruck) {
        super(generator, speed, color);
        this.railtruck = railtruck;
    }

    public int getRailtruck() {
        return railtruck;
    }

    public void setRailtruck(int railtruck) {
        this.railtruck = railtruck;
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
                ", railtruck=" + railtruck +
                ", speed=" + speed +
                ", color='" + color + '\'' +
                '}';
    }

}
