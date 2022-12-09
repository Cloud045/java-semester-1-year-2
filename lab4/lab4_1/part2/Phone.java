package lab4.lab4_1.part2;

public class Phone {
    private int number;
    private String model;
    private int weight;

    public void receiveCall(String name) {
        System.out.println("Звонит {" + name + "}");
    }

    public void receiveCall(String name, int number) {
        System.out.println("Звонит {" + name + "," + number + "}");
    }

    public int getNumber() {
        return number;
    }

    public int getWeight() {
        return weight;
    }

    public String getModel() {
        return model;
    }

    public void sendMessage(int... arr) {
        int n = arr.length;
        for (int i = 0; i < n; ++i) {
            System.out.println("Number " + (i + 1) + ": " + arr[i]);
        }
    }

    public Phone() {
    }

    public Phone(int number, String model) {
        this.model = model;
        this.number = number;
    }

    public Phone(int number, String model, int weight) {
        this.model = model;
        this.number = number;
        this.weight = weight;
    }

    @Override
    public String toString() {
        return "Phone{" +
                "number=" + number +
                ", model='" + model + '\'' +
                ", weight=" + weight +
                '}';
    }
}
