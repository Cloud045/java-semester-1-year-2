package lab4;

public class Monitor {
    private String resolution;
    private int Hz;
    private double size;

    public Monitor(String resolution, int Hz, double size) {
        this.resolution = resolution;
        this.Hz = Hz;
        this.size = size;
    }

    public double getSize() {
        return size;
    }

    public int getHz() {
        return Hz;
    }

    public String getResolution() {
        return resolution;
    }

    @Override
    public String toString() {
        return "Minitor:{"
                + "Resolution:" + resolution + ", "
                + "Hz:" + Hz + ", "
                + "Size:" + size + "}";
    }
}
