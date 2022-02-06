// https://www.acmicpc.net/problem/11724
import java.io.*;
import java.util.*;

public class Main
{
    static int arr[][];
    static int points[];
    static int n, m;

    static void dfs(int x)
    {
        for(int i = 1; i <= n; ++i)
        {
            if(arr[x][i] == 1 && points[i] == 0) {
                points[i] = 1;
                dfs(i);
            }
        }
    }

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine(), " ");
        
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[n + 1][n + 1];
        points = new int[n + 1];
		
        for(int i = 0; i < m; ++i)
        {
            st = new StringTokenizer(br.readLine(), " ");
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            arr[u][v] = arr[v][u] = 1;
        }

        int answer = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(points[i] == 0) {
                dfs(i);
                ++answer;
            }
        }
        
        System.out.println(answer);
		return;
	}
}
