package Lesson3;

import java.util.Scanner;

public class L5_37 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        String str = "";
        while (n != 0) {
            str = (n % 2) + str;
            n /= 2;
        }
        System.out.println(str);
    }
}
