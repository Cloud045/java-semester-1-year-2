package lab4;

public class Memory {
    private int Capacity;

    public Memory(int Capacity) {
        this.Capacity = Capacity;
    }

    public int getCapacity() {
        return Capacity;
    }

    @Override
    public String toString() {
        return "Processor:{"
                + "Capacity:" + Capacity + "}";
    }
}
