// https://www.acmicpc.net/problem/1924
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        Calendar cal = Calendar.getInstance();
        int month = Integer.parseInt(st.nextToken());
        int day = Integer.parseInt(st.nextToken());

        cal.set(Calendar.YEAR, 2007);
        cal.set(Calendar.MONTH, month-1);
        cal.set(Calendar.DAY_OF_MONTH, day);

        String[] yoil = {"", "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
        System.out.println(yoil[cal.get(Calendar.DAY_OF_WEEK)]);
    }
}