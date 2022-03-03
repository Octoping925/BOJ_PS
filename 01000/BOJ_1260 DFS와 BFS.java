// https://www.acmicpc.net/problem/1260
import java.io.*;
import java.util.*;

public class Main
{
    static int arr[][];
    static int points[];
    static int n, m, v;

    static void dfs(int x)
    {
        System.out.print(x);
        System.out.print(" ");
        points[x] = 1;
        for(int i = 1; i <= n; ++i)
        {
            if(arr[x][i] == 1 && points[i] == 0)
                dfs(i);
        }
    }

    static void bfs(int x)
    {
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(x);
        points[x] = 1;
        while(!q.isEmpty())
        {
            int now = q.poll();
            System.out.print(now);
            System.out.print(" ");
            for(int i = 1; i <= n; ++i)
            {
                if(arr[now][i] == 1 && points[i] == 0) {
                    q.add(i);
                    points[i] = 1;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine(), " ");
        
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        v = Integer.parseInt(st.nextToken());

        arr = new int[n + 1][n + 1];
        points = new int[n + 1];
        
        for(int i = 0; i < m; ++i)
        {
            st = new StringTokenizer(br.readLine(), " ");
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            arr[u][v] = arr[v][u] = 1;
        }

        dfs(v);
        System.out.println();
        Arrays.fill(points, 0);
        bfs(v);
        return;
    }
}
