package Lesson5;

public class TestCircle {
    public static void main(String[] args) {
        Circle cirlce1 = new Circle();
        System.out.println("The area of the circle of  radius" + cirlce1.radius + " is " + cirlce1.getArea());
        Circle cirlce2 = new Circle(25);
        System.out.println("The area of the circle of  radius" + cirlce2.radius + " is " + cirlce2.getArea());
        Circle cirlce3 = new Circle(125);
        System.out.println("The area of the circle of  radius" + cirlce3.radius + " is " + cirlce3.getArea());
        cirlce2.radius = 100;
        System.out.println("The area of the circle of  radius" + cirlce2.radius + " is " + cirlce2.getArea());
    }
}

class Circle {
    double radius;

    Circle() {
        radius = 1;
    }

    Circle(double newradius) {
        radius = newradius;
    }

    double getArea() {
        return radius * radius * Math.PI;
    }

    double getPerimeter() {
        return 2 * radius * Math.PI;
    }

    void setRadius(double newradius) {
        radius = newradius;
    }
}
