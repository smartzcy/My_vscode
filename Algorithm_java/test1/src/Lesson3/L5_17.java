package Lesson3;

import java.util.Scanner;

public class L5_17 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        for (int i = 1; i <= n; i++) {
            for (int j = n - i; j >= 1; j--)
                System.out.print("  ");
            for (int j = i; j >= 1; j--)
                System.out.print(j + " ");
            for (int j = 2; j <= i; j++)
                System.out.print(j + " ");
            System.out.println();
        }
    }
}
