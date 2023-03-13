package Lesson3;

public class L5_32 {
    public static void main(String[] args) {
        int num = (int) (Math.random() * 10);
        int num2 = (int) (Math.random() * 10);
        while (num2 == num) {
            num2 = (int) (Math.random() * 10);
        }
        System.out.println(num + "" + num2);
    }
}
