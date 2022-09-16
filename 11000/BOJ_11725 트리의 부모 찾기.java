// https://www.acmicpc.net/problem/11725
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());

        LinkedList<Integer>[] child = new LinkedList[n + 1];
        int[] parents = new int[n + 1];

        for(int i = 1; i <= n; ++i) {
            child[i] = new LinkedList<>();
        }

        for(int i = 1; i < n; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            child[x].add(y);
            child[y].add(x);
        }

        Queue<Integer> q = new LinkedList<>();
        q.add(1);

        while(!q.isEmpty()) {
            int p = q.poll();

            for(int i : child[p]) {
                if(parents[i] == 0) {
                    parents[i] = p;
                    q.add(i);
                }
            }
        }

        for(int i = 2; i <= n; ++i) {
            bw.write(Integer.toString(parents[i]));
            bw.newLine();
        }

        bw.flush();
    }
}