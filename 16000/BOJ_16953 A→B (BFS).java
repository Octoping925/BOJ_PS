// https://www.acmicpc.net/problem/16953
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Queue<Integer> q = new LinkedList<>();
        q.add(n);

        int cnt = 1;
        while(!q.isEmpty()) {
            int qSize = q.size();
            while(qSize-->0) {
                int p = q.poll();

                if (p == m) {
                    System.out.print(cnt);
                    return;
                }

                if (p * 2 <= m) {
                    q.add(p*2);
                }
                if((long)p*10 + 1 <= m) {
                    q.add(p*10 + 1);
                }
            }

            ++cnt;
        }

        System.out.print(-1);
    }
}