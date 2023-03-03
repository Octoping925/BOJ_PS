// https://www.acmicpc.net/problem/16173
import java.io.*;
import java.util.*;

public class Main {
    static int[][] map;
    static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        map = new int[n+1][n+1];

        for(int i = 1; i <= n; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            for(int j = 1; j <= n; ++j) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(DFS(1, 1) ? "HaruHaru" : "Hing");
    }

    static boolean DFS(int x, int y) {
        if(x == n && y == n) {
            return true;
        }

        int dist = map[x][y];
        
        if(dist == 0) {
            return false;
        }

        int newX = x + dist;
        int newY = y + dist;

        if(newX <= n) {
            boolean isArrived = DFS(newX, y);
            if(isArrived) return true;
        }
        if(newY <= n) {
            boolean isArrived = DFS(x, newY);
            if(isArrived) return true;
        }

        return false;
    }
}