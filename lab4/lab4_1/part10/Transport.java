package lab4.lab4_1.part10;

public abstract class Transport {
    protected double generator;
    protected double speed;

    protected String color = "none";

    public void setColor(String color) {
        this.color = color;
    }

    public String getColor() {
        return color;
    }

    public double getGenerator() {
        return generator;
    }

    public double getSpeed() {
        return speed;
    }

    public void setGenerator(double generator) {
        this.generator = generator;
    }

    public void setSpeed(double speed) {
        this.speed = speed;
    }

    public Transport(double generator, double speed, String color) {
        this.generator = generator;
        this.speed = speed;
        this.color = color;
    }

    public abstract double TimeTrans(double distance);

    public abstract double CostTrans(double time, double oilprice);

    @Override
    public String toString() {
        return "Transport{" +
                "generator=" + generator +
                ", speed=" + speed +
                ", color='" + color + '\'' +
                '}';
    }
}
