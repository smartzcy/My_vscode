package Lesson3;

import java.util.Scanner;

public class L5_45 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double[] num = new double[15];
        double sum = 0;
        for (int i = 1; i <= 10; i++) {
            num[i] = scanner.nextDouble();
            sum += num[i];
        }
        scanner.close();
        System.out.printf("%.2f\n", sum / 10.0);
        double num2 = 0;
        for (int i = 1; i <= 10; i++) {
            num2 += num[i] * num[i];
        }
        System.out.printf("%.5f", Math.pow((num2 - sum * sum / 10.0) / 9.0, 0.5));
    }
}
