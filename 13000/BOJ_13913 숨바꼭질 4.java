// https://www.acmicpc.net/problem/13913
import java.io.*;
import java.util.*;

class Point {
    public int cnt;
    public int pos;

    Point(int c, int p) {
        cnt = c;
        pos = p;
    }

    public Point move(int pos) {
        return new Point(cnt + 1, pos);
    }
}

public class Main {
    static Queue<Point> q = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        if(k < n) {
            System.out.println(n - k);
            StringBuilder sb = new StringBuilder();
            for(int i = n; i >= k; i--) {
                sb.append(i).append(" ");
            }
            System.out.println(sb);
            return;
        }

        int[] arr = new int[200010];

        Arrays.fill(arr, 100001);
        q.add(new Point(0, n));

        while(!q.isEmpty()) {
            int len = q.size();

            for(int i = 0; i < len; ++i) {
                Point p = q.poll();

                if(p.cnt < arr[p.pos]) {
                    arr[p.pos] = p.cnt;
                }
                else continue;

                if(p.pos == k) {
                    continue;
                }

                if(p.pos > 0) q.add(p.move(p.pos - 1));
                if(p.pos < k) q.add(p.move(p.pos + 1));
                if(p.pos != 0 && p.pos < k) q.add(p.move(p.pos * 2));
            }
        }

        System.out.println(arr[k]);
        findPath(arr, n, k);
    }

    private static void findPath(int[] arr, int start, int end) {
        Deque<Integer> dq = new ArrayDeque<>();

        int pos = end;
        while(pos != start) {
            if(arr[pos-1] == arr[pos] - 1) {
                dq.addFirst(pos);
                pos--;
            }
            else if(pos % 2 == 0 && arr[pos/2] == arr[pos] - 1) {
                dq.addFirst(pos);
                pos /= 2;
            }
            else if(arr[pos+1] == arr[pos] - 1) {
                dq.addFirst(pos);
                pos++;
            }
        }
        dq.addFirst(start);

        for(int i : dq) {
            System.out.print(i + " ");
        }
    }
}
