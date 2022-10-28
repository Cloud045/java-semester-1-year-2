package lab2.part5;

public class dog {
    private String name;
    private int age;

    public dog() {
        this.name = "Bull";
        this.age = 2;
    }

    public dog(String name, int age) {
        this.age = age;
        this.name = name;
    }

    public int ToHumanAge() {
        return this.age * 7;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Dog{" +
                "name: " + this.name + ", " +
                "age: " + this.age + "}"
                ;
    }
}
