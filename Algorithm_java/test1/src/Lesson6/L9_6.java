import java.util.Date;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Calendar;
import java.util.GregorianCalendar;

public class L9_6 {
    public static void main(String[] args) {
        int a[] = new int[100000];
        StopWatch stopWatch = new StopWatch();
        for (int i = 0; i < 100000; i++) {
            a[i] = 100000 - i;
        }
        stopWatch.start();
        Arrays.sort(a);
        stopWatch.stop();
        System.out.println(stopWatch.getElapsedTime());
    }

    static class StopWatch {
        private Date startTime;
        private Date endTime;

        StopWatch() {
            Calendar now = new GregorianCalendar();
            this.startTime = now.getTime();
        }

        void start() {
            Calendar now = new GregorianCalendar();
            this.startTime = now.getTime();
        }

        void stop() {
            Calendar now = new GregorianCalendar();
            this.endTime = now.getTime();
        }

        long getElapsedTime() {
            return endTime.getTime() - startTime.getTime();
        }
    }
}
