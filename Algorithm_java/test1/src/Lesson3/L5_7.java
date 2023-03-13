package Lesson3;

public class L5_7 {
    public static void main(String[] args) {
        double num = 10000;
        double zeng = 0.05;
        for (int i = 1; i <= 10; i++) {
            num = num * (1 + zeng);
        }
        System.out.println((int) num);
        double sum = 0;
        for (int i = 1; i <= 4; i++) {
            sum += num;
            num *= (1 + zeng);
        }
        System.out.println((int) sum);
    }
}
