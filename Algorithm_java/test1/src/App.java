public class App {
    public static void main(String[] args) throws Exception {
        boolean[][] x = new boolean[3][];
        x[0] = new boolean[1];
        x[1] = new boolean[2];
        x[2] = new boolean[3];
        System.out.println(x[2][2]);
    }
}
