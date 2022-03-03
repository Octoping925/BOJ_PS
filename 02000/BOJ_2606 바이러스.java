// https://www.acmicpc.net/problem/2606
import java.io.*;
import java.util.*;

public class Main
{
    static int arr[][];
    static int points[];
    static int n, m, answer;

    static void dfs(int x)
    {
        points[x] = 1;
        ++answer;
        for(int i = 1; i <= n; ++i)
        {
            if(arr[x][i] == 1 && points[i] == 0)
                dfs(i);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        arr = new int[n + 1][n + 1];
        points = new int[n + 1];
        
        for(int i = 0; i < m; ++i)
        {
            st = new StringTokenizer(br.readLine(), " ");
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            arr[u][v] = arr[v][u] = 1;
        }
        
        answer = 0;
        dfs(1);
        System.out.println(answer - 1);
        return;
    }
}
