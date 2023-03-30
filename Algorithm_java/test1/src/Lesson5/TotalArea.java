package Lesson5;

public class TotalArea {
    public static void main(String[] args) {
        Circle3[] circleArray;
        circleArray = creatCircleArray();
        printCircleArray(circleArray);
    }

    private static void printCircleArray(Circle3[] circleArray) {
        System.out.printf("%-30s%-15s\n", "radius", "Area");
        for (int i = 0; i < circleArray.length; i++) {
            System.out.printf("%-3.f%-15f\n", circleArray[i].getRadius(), circleArray[i].getArea());
        }
        System.out.println("_________________________");
        System.out.printf("%-30s%-15f\n", "The total area of circle is", sum(circleArray));
    }

    private static double sum(Circle3[] circleArray) {
        double sum = 0;
        for (int i = 0; i < circleArray.length; i++) {
            sum += circleArray[i].getArea();
        }
        return sum;
    }

    public static Circle3[] creatCircleArray() {
        Circle3[] circleArray = new Circle3[5];
        for (int i = 0; i < circleArray.length; i++) {
            circleArray[i] = new Circle3(Math.random() * 100);
        }
        return circleArray;
    }
}
