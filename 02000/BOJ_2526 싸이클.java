// https://www.acmicpc.net/problem/2526
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());

        Map<Integer, Integer> map = new HashMap<>();

        int cnt = 0;
        int curNum = n;
        while(++cnt > 0) {
            map.put(curNum, cnt);

            curNum = (curNum * n) % p;
            if(map.containsKey(curNum)) {
                System.out.println(cnt - map.get(curNum) + 1);
                break;
            }
        }
    }
}