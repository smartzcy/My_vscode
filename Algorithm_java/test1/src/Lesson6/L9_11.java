import java.util.Scanner;

public class L9_11 {
    public static void main(String[] args) {
        int a, b, c, d, e, f;
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        e = scanner.nextInt();
        f = scanner.nextInt();
        scanner.close();
        LinearEquation linearEquation = new LinearEquation(a, b, c, d, e, f);
        if (linearEquation.isSolvable()) {
            System.out.println("X = " + linearEquation.getX() + "  Y = " + linearEquation.getY());
        } else {
            System.out.println("The equation has no solution.");
        }
    }

    static class LinearEquation {
        private int a, b, c, d, e, f;

        public int getA() {
            return a;
        }

        public int getB() {
            return b;
        }

        public int getC() {
            return c;
        }

        public int getD() {
            return d;
        }

        public int getE() {
            return e;
        }

        public int getF() {
            return f;
        }

        public LinearEquation(int a, int b, int c, int d, int e, int f) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
            this.e = e;
            this.f = f;
        }

        public boolean isSolvable() {
            return (this.a * this.d - this.b * this.c == 0 ? false : true);
        }

        double getX() {
            return ((e * d - b * f) / (a * d - b * c));
        }

        double getY() {
            return ((a * f - e * c) / (a * d - b * c));
        }
    }
}
