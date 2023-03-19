package Lesson4;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class L7_5 {
    public static void main(String[] args) {
        System.out.print("Enter 10 numbers:");
        Scanner scanner = new Scanner(System.in);
        Set<Integer> s = new HashSet<>();
        int maxx = 0;
        for (int i = 0; i < 10; i++) {
            int n = scanner.nextInt();
            maxx = Math.max(maxx, n);
            s.add(n);
        }
        scanner.close();
        System.out.println(maxx);
        for (int n : s) {
            System.out.print(n + " ");
        }
    }
}
