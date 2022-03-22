//https://www.acmicpc.net/problem/2178
import java.io.*;
import java.util.*;

public class Main
{
    static char[][] maze;
    static int[][] visited;
    static int min, n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        maze = new char[n+1][m+1];
        visited = new int[n+1][m+1];
        min = n * m;
        
        for(int i = 0; i < n; ++i) {
            maze[i] = br.readLine().toCharArray();
            for(int j = 0; j < m; ++j) visited[i][j] = min;
        }
        
        dfs(0,0,1);
        System.out.println(min);
        return;
    }

    static void dfs(int x, int y, int len)
    {
        if(x == n-1 && y == m-1) {
            if(len < min) min = len;
            return;
        }
        if(len > min) return;
        visited[x][y] = len;
        
        if(x > 0 && len+1 < visited[x-1][y] && maze[x-1][y] == '1') {
            dfs(x-1, y, len+1);
        }
        if(y > 0 && len+1 < visited[x][y-1] && maze[x][y-1] == '1') {
            dfs(x, y-1, len+1);
        }
        if(x < n-1 && len+1 < visited[x+1][y] && maze[x+1][y] == '1') {
            dfs(x+1, y, len+1);
        }
        if(y < m-1 && len+1 < visited[x][y+1] && maze[x][y+1] == '1') {
            dfs(x, y+1, len+1);
        }
    }
}
