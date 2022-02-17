// https://www.acmicpc.net/problem/1697
import java.io.*;
import java.util.*;

class Point {
    public int cnt;
    public int pos;
    Point(int c, int p) {
        cnt = c;
        pos = p;
    }
}

public class Main
{
    static Queue<Point> q = new LinkedList<Point>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

		int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        if(k < n) {
            System.out.println(n - k);
            return;
        }
    
        int arr[] = new int[200010];
        Arrays.fill(arr, 100001);
        q.add(new Point(0, n));

        while(!q.isEmpty())
        {
            int len = q.size();
            for(int i = 0; i < len; ++i)
            {
                Point p = q.poll();
                if(p.cnt < arr[p.pos]) arr[p.pos] = p.cnt;
                else continue;

                if(p.pos == k) {
                    continue;
                }

                if(p.pos > 0) q.add(new Point(p.cnt + 1, p.pos - 1));
                if(p.pos < k) q.add(new Point(p.cnt + 1, p.pos + 1));
                if(p.pos != 0 && p.pos < k) q.add(new Point(p.cnt, p.pos * 2));
            }
        }
        System.out.println(arr[k]);
		return;
	}
}
