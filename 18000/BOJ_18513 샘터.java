// https://www.acmicpc.net/problem/18513
import java.io.*;
import java.util.*;

public class Main {
    static HashMap<Integer, Boolean> checked = new HashMap<>();
    static Queue<Integer> home = new LinkedList<>();
    static long unhappy = 0;
    static long dis = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine(), " ");
        for(int i = 0; i < n; ++i) {
            int p = Integer.parseInt(st.nextToken());
            home.add(p);
            checked.put(p, true);
        }

        int cnt = 0;
        while(cnt < k)
        {
            int len = home.size();
            for(int i = 0; i < len; ++i) {
                int p = home.poll();
                if (!checked.containsKey(p - 1)) {
                    buildHome(p - 1);
                    ++cnt;
                }
                if (cnt == k) {
                    break;
                }
                if (!checked.containsKey(p + 1)) {
                    buildHome(p + 1);
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

    public static void buildHome(int idx) {
        home.add(idx);
        checked.put(idx, true);
        unhappy += dis;
    }
}