package lab2.part3;

public class circle extends point {
    private double r;
    private String color;

    public circle(double x, double y, double r, String color) {
        this.setX(x);
        this.setY(y);
        this.r = r;
        this.color = color;
    }

    public void setR(double r) {
        this.r = r;
    }

    public double getR() {
        return r;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public String toString() {
        return "Circle{" +
                "x: " + this.getX() + ", " +
                "y: " + this.getY() + ", " +
                "r: " + this.getR() + ", " +
                "color: " + this.getColor() + "}"
                ;
    }
}
