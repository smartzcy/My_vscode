import java.util.Scanner;

public class L9_10 {
    public static void main(String[] args) {
        QuardraticEquation x = new QuardraticEquation();
        Scanner scanner = new Scanner(System.in);
        x.setA(scanner.nextInt());
        x.setB(scanner.nextInt());
        x.setC(scanner.nextInt());
        int y = x.getDiscriminant();
        if (y > 0) {
            System.out.println(x.getRoot1() + " " + x.getRoot2());
        } else if (y == 0) {
            System.out.println(x.getRoot1());
        } else {
            System.out.println("The equation has no roots");
        }
    }

    static class QuardraticEquation {
        private int a, b, c;

        public void setA(int a) {
            this.a = a;
        }

        public void setB(int b) {
            this.b = b;
        }

        public void setC(int c) {
            this.c = c;
        }

        public int getA() {
            return a;
        }

        public int getB() {
            return b;
        }

        public int getC() {
            return c;
        }

        QuardraticEquation() {

        }

        public int getDiscriminant() {
            return this.b * this.b - 4 * this.a * this.c;
        }

        public double getRoot1() {
            return (-this.b + Math.sqrt(getDiscriminant())) / (double) (2 * a);
        }

        public double getRoot2() {
            return (-this.b - Math.sqrt(getDiscriminant())) / (double) (2 * a);
        }
    }
}
