package lab2.part2;

public class ball {
    private double x;
    private double y;

    public ball() {
        this.x = 0;
        this.y = 0;
    }

    public ball(double x, double y) {
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

    public void setXY(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public void move(double xdisp, double ydisp) {
        this.x += xdisp;
        this.y += ydisp;
    }

    @Override
    public String toString() {
        return "Ball{" +
                "x:" + x + ", " +
                "y:" + y + '}'
                ;
    }
}
