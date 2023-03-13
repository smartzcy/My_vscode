package Lesson3;

import java.util.Scanner;

public class L5_19 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        for (int i = 1; i <= n; i++) {
            for (int j = n - i; j >= 1; j--)
                System.out.print("  ");
            for (int j = 1; j <= i; j++)
                System.out.print((int) Math.pow(2, j - 1) + " ");
            for (int j = i - 1; j >= 1; j--)
                System.out.print((int) Math.pow(2, j - 1) + " ");
            System.out.println();
        }
    }
}
