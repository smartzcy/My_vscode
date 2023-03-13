package Lesson3;

import java.util.Scanner;

public class L5_25 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        double pi = 0;
        for (int i = 1; i <= n; i++) {
            pi += Math.pow(-1, i + 1) / (double) (2 * i - 1);
        }
        System.out.println(4 * pi);
    }
}
