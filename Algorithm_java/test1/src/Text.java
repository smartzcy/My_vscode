import java.util.*;

public class Text {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double side = in.nextDouble();
        String color = in.next();
        boolean filled = in.nextBoolean();
        Octagon octagon1 = new Octagon(color, filled, side);
        System.out.printf("%.2f %.2f\n", octagon1.getArea(), octagon1.getPerimeter());
        Octagon octagon2 = (Octagon) (octagon1.clone());
        System.out.println(octagon1.compareTo(octagon2));
    }
}

abstract class GeometricObject {
    private double side;
    private String color;
    private boolean filled;

    GeometricObject(String co, boolean st, double s) {
        color = co;
        filled = st;
        side = s;
    }

    public abstract double compareTo();
}

class Octagon extends GeometricObject implements Comparable<Octagon>, Cloneable {
    private double side;
    private String color;
    private boolean filled;

    Octagon(String co, boolean st, double s) {
        super(co, st, s);
        side = s;
        color = co;
        filled = st;
    }

    @Override
    public double compareTo() {
        return 0;
    }

    double getArea() {
        return (2 + 4.0 / Math.sqrt(2)) * side * side;
    }

    double getPerimeter() {
        return side * 8;
    }

    @Override
    public int compareTo(Octagon o) {
        if (this.side > o.side)
            return 1;
        else if (this.side == o.side)
            return 0;
        else
            return -1;
    }

    @Override
    protected Object clone() {
        try {
            return super.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return color;
    }
}