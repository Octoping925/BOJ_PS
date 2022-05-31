// https://www.acmicpc.net/problem/11652
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)  throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<Long, Integer> hm = new HashMap<>();

        long maxNum = 0;
        int maxCnt = 0;

        int n = Integer.parseInt(br.readLine());
        while(n-->0) {
            long num = Long.parseLong(br.readLine());
            int cnt = hm.containsKey(num) ? hm.get(num) + 1 : 1;

            if(cnt > maxCnt) {
                maxNum = num;
                maxCnt = cnt;
            }
            else if(cnt == maxCnt && num < maxNum) {
                maxNum = num;
            }

            hm.put(num, cnt);
        }

        System.out.println(maxNum);
    }
}