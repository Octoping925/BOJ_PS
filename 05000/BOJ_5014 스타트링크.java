// https://www.acmicpc.net/problem/5014
import java.io.*;
import java.util.*;

class Point {
    public int pos, cnt;
    Point(int pos, int cnt) {
        this.pos = pos;
        this.cnt = cnt;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int f = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int g = Integer.parseInt(st.nextToken());
        int u = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int[] arr = new int[f+1];
        Arrays.fill(arr, -1);

        bfs(f, s, g, u, d, arr);

        System.out.println(arr[g] != -1 ? arr[g] : "use the stairs");
    }

    static void bfs(int f, int s, int g, int u, int d, int[] arr) {
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(s, 0));
        while(!q.isEmpty()) {
            Point p = q.poll();

            if(arr[p.pos] != -1 && p.cnt >= arr[p.pos]) continue;
            arr[p.pos] = p.cnt;
            if(p.pos == g) continue;


            if(p.pos - d >= 1) {
                q.add(new Point(p.pos - d, p.cnt + 1));
            }
            if(p.pos + u <= f) {
                q.add(new Point(p.pos + u, p.cnt + 1));
            }
        }
    }
}