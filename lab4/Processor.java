package lab4;

public class Processor {
    private int core;
    private int thread;

    public Processor(int core, int thread) {
        this.core = core;
        this.thread = thread;
    }

    public int getCore() {
        return core;
    }

    public int getThread() {
        return thread;
    }

    @Override
    public String toString() {
        return "Processor:{"
                + "Core:" + core + ", "
                + "Thread:" + thread + "}";
    }
}
