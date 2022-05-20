// https://www.acmicpc.net/problem/1541
import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)  throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), "\\+|-", true);

        int result = Integer.parseInt(st.nextToken());

        int minus = 1;
        while(st.hasMoreTokens()) {
            String oper = st.nextToken();
            if(minus == -1 || oper.equals("-")) {
                minus = -1;
            }

            int num = Integer.parseInt(st.nextToken());
            result += num * minus;
        }

        System.out.println(result);
    }
}