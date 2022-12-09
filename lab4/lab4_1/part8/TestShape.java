package lab4.lab4_1.part8;

public class TestShape {
    public static void main(String[] args) {
        Circle circle = new Circle(50, "Sun", true);
        System.out.println(circle);
        System.out.println("Circle Area= " + circle.getArea());
        System.out.println("Circle Perimeter= " + circle.getPerimeter());
        Rectangle rectangle = new Rectangle();
        rectangle.setWidth(6.5);
        rectangle.setLength(4);
        rectangle.setFilled(false);
        System.out.println(rectangle);
        System.out.println("Rectangle Area= " + rectangle.getArea());
        System.out.println("Rectangle Perimeter= " + rectangle.getPerimeter());
        Square square = new Square(1.6, "yellow", true);
        System.out.println(square);
        square.setSide(16);
        System.out.println("Square New Side= " + square.getSide());
        System.out.println("Square Area= " + square.getArea());
        System.out.println("Square Perimeter= " + square.getPerimeter());

    }


}
