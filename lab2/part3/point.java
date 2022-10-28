package lab2.part3;

public class point {
    private double x;
    private double y;

    public point() {
        this.x = 0;
        this.y = 0;
    }

    public point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }
}
