package Lesson4;

import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class L7_3 {
    public static void main(String[] args) {
        System.out.print("Enter the integers between 1 and 100:");
        TreeMap<Integer, Integer> m = new TreeMap<>();
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int n = scanner.nextInt();
            if (n == 0)
                break;
            if (m.containsKey(n)) {
                m.replace(n, m.get(n) + 1);
            } else {
                m.put(n, 1);
            }
        }
        scanner.close();
        for (Map.Entry<Integer, Integer> entry : m.entrySet()) {
            System.out.println(entry.getKey().toString() + " occurs " + entry.getValue().toString() + " time"
                    + (entry.getValue() > 1 ? "S" : ""));
        }
    }
}
