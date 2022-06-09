// https://www.acmicpc.net/problem/25195
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        LinkedList<Integer>[] map = new LinkedList[n+1];
        for(int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            if(map[x] == null) map[x] = new LinkedList<>();
            map[x].add(y);
        }

        int k = Integer.parseInt(br.readLine());

        HashSet<Integer> fanclub = new HashSet<>();
        st = new StringTokenizer(br.readLine());
        while(k-->0) {
            fanclub.add(Integer.parseInt(st.nextToken()));
        }


        Queue<Integer> q = new LinkedList<>();
        HashSet<Integer> visited = new HashSet<>();
        q.add(1);

        boolean yesoryes = false;
        while(!q.isEmpty()) {
            int p = q.poll();
            visited.add(p);
            if(fanclub.contains(p)) continue;

            if(map[p] == null) {
                yesoryes = true;
                break;
            }

            for(int i : map[p]) {
                if(!visited.contains(i)) {
                    q.add(i);
                }
            }
        }

        System.out.print(yesoryes ? "yes" : "Yes");
    }
}