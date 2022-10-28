package lab2.part6;

public class circle {
    private double x;
    private double y;
    private double r;
    private String color;

    public circle(double x, double y, double r, String color) {
        this.x = x;
        this.y = y;
        this.r = r;
        this.color = color;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public void setR(double r) {
        this.r = r;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public double getR() {
        return r;
    }

    public String getColor() {
        return color;
    }

    public double getPerimeter() {
        return Math.PI * this.r;
    }

    @Override
    public String toString() {
        return "circle{" +
                "x: " + this.x + ", " +
                "y: " + this.y + ", " +
                "r: " + this.r + ", " +
                "color: " + this.color + "}"
                ;
    }
}
