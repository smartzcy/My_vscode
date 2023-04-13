import java.sql.Date;

public class L9_3 {
    public static void main(String[] args) {
        Date date = new Date(10000);
        for (long i = 10000; i <= 100000000000L; i *= 10) {
            date.setTime(i);
            System.out.println(date.toString());
        }
    }
}
