package Lesson8;

public class Circle extends GeometricObject {
    private double radius;

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public Circle() {

    }

    public Circle(double radius) {
        this.radius = radius;
    }

    public Circle(double radius, String color, boolean filled) {
        this.radius = radius;
        this.setColor(color);
        this.setFilled(filled);
    }

    public double getArea() {
        return radius * radius * Math.PI;
    }

    public double getDiameter() {
        return 2 * radius;
    }

    public double getPerimeter() {
        return 2 * Math.PI * radius;
    }

    public void printCircle() {
        System.out.println("The circle is created " + getDiameter() + " and the radius is " + radius);
    }
}
