import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;

public class L11_16 {
    public static void main(String[] args) {
        HashSet<Integer> hashSet = new HashSet<>();
        Random random = new Random();
        int a = random.nextInt(100);
        int b = random.nextInt(100);
        System.out.printf("What is %d + %d? ", a, b);
        Scanner Scanner = new Scanner(System.in);
        int num = Scanner.nextInt();
        while (num != a + b) {
            if (hashSet.contains(num))
                System.out.printf("You already entered %d\n", num);
            hashSet.add(num);
            System.out.printf("Wrong answer, Try again. What is %d + %d? ", a, b);
            num = Scanner.nextInt();
        }
        System.out.println("You got it!");
        Scanner.close();
    }
}
