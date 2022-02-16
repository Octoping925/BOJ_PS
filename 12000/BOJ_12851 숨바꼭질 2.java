// https://www.acmicpc.net/problem/12851
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
            System.out.println(1);
            return;
        }
    
        int arr[][] = new int[200010][2];
        for(int i = 0; i <= 200000; ++i) arr[i][0] = 100001;
        q.add(new Point(0, n));

        while(!q.isEmpty())
        {
            int len = q.size();
            for(int i = 0; i < len; ++i)
            {
                Point p = q.poll();
                if(p.cnt < arr[p.pos][0]) {
                    arr[p.pos][0] = p.cnt;
                    arr[p.pos][1] = 1;
                }
                else if(p.cnt == arr[p.pos][0]) arr[p.pos][1]++;
                else continue;

                if(p.pos == k) {
                    continue;
                }

                if(p.pos > 0) q.add(new Point(p.cnt + 1, p.pos - 1));
                if(p.pos < k) q.add(new Point(p.cnt + 1, p.pos + 1));
                if(p.pos != 0 && p.pos < k) q.add(new Point(p.cnt + 1, p.pos * 2));
            }
        }
        System.out.println(arr[k][0]);
        System.out.println(arr[k][1]);
		return;
	}
}

