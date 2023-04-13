package Lesson8;

public class CasstingDemo {
    public static void main(String[] args) {
        Object object1 = new Circle(1);
        Object object2 = new Rectangle(1, 1);

    }

    public static void displayObject(Object object) {
        if (object instanceof Circle) {
            System.out.println("The circle area is " + ((Circle) object).getArea());
            System.out.println("The Circle diameter is " + ((Circle) object).getDiameter());
        } else if (object instanceof Rectangle) {
            System.out.println("The rectangle area is " + ((Rectangle) object).getArea());
        }
    }
}
