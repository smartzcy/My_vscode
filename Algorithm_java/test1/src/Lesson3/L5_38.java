package Lesson3;

import java.util.Scanner;

public class L5_38 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        String str = "";
        while (n != 0) {
            str = (n % 8) + str;
            n /= 8;
        }
        System.out.println(str);
    }
}
