package Lesson4;

import java.util.Scanner;

public class L7_19 {
    public static boolean isSorted(int[] list) {
        int num = list[0];
        for (int i = 1; i < list.length; i++) {
            if (num > list[i])
                return false;
            num = list[i];
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] num = new int[1000];
        for (int i = 0; i < n; i++) {
            num[i] = scanner.nextInt();
        }
        scanner.close();
        if (isSorted(num)) {
            System.out.println("The list is already sorted");
        } else {
            System.out.println("The lis is not sorted");
        }
    }
}
