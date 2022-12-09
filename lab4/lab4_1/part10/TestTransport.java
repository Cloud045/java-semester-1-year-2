package lab4.lab4_1.part10;

public class TestTransport {
    public static void main(String[] args) {
        Plane plane = new Plane(1024.5, 876.5, "white", 500, Plane.Brand.Aeroflot);
        System.out.println(plane);
        System.out.println("Plane capacity= " + plane.getCapacity());
        Car car = new Car(215.6, 176.5, "black", Car.Brand.Bugatti);
        System.out.println(car);
        System.out.println("Car TimeTrans= " + car.TimeTrans(100));
        System.out.println("Car CostTrans= " + car.CostTrans(car.TimeTrans(100), 24.5));
    }
}
