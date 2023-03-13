package Lesson3;

import java.util.Scanner;

public class L5_26 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        double pi = 1;
        int sum = 1;
        for (int i = 1; i <= n; i++) {
            pi += 1.0 / sum;
            sum *= (i + 1);
        }
        System.out.println(pi);
    }
}
