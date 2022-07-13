// https://www.acmicpc.net/problem/18513
import java.io.*;
import java.util.*;

public class Main {
    static HashSet<Integer> checked = new HashSet<>();
    static Queue<Integer> home = new LinkedList<>();
    static long unhappy = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine(), " ");
        while(st.hasMoreTokens()) {
            int p = Integer.parseInt(st.nextToken());
            home.add(p);
            checked.add(p);
        }

        int cnt = 0;
        long dis = 1;

        while(cnt < k)
        {
            int len = home.size();
            for(int i = 0; i < len; ++i) {
                int p = home.poll();
                if (!checked.contains(p - 1)) {
                    buildHome(p - 1, dis);
                    ++cnt;
                }
                if (cnt == k) {
                    break;
                }
                if (!checked.contains(p + 1)) {
                    buildHome(p + 1, dis);
                    ++cnt;
                }
                if(cnt == k) {
                    break;
                }
            }
            ++dis;
        }

        System.out.println(unhappy);
    }

    public static void buildHome(int idx, long dis) {
        home.add(idx);
        checked.add(idx);
        unhappy += dis;
    }
}