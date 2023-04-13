import java.util.Calendar;
import java.util.GregorianCalendar;

public class L9_5 {
    public static void main(String[] args) {
        Calendar cal = new GregorianCalendar();
        System.out
                .println(cal.get(Calendar.YEAR) + " " + cal.get(Calendar.MONTH) + " " + cal.get(Calendar.DAY_OF_MONTH));
        cal.setTimeInMillis(1234567898765L);
        System.out
                .println(cal.get(Calendar.YEAR) + " " + cal.get(Calendar.MONTH) + " " + cal.get(Calendar.DAY_OF_MONTH));
    }
}
