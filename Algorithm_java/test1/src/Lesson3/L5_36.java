package Lesson3;

import java.util.Scanner;

public class L5_36 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        scanner.close();
        int sum = 0;
        for (int i = 0; i < str.length(); i++) {
            sum += (str.charAt(i) - '0') * (i + 1);
        }
        sum %= 11;
        if (sum == 10)
            System.out.println(str + 'X');
        else
            System.out.println(str + sum);
    }
}
