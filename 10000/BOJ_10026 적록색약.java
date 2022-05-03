// https://www.acmicpc.net/problem/10026
import java.io.*;
import java.util.*;

class Point {
    public int x, y;
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {
    static int n;
    static char[][] arr;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        arr = new char[n][n];
        for(int i = 0; i < n; ++i) {
            arr[i] = br.readLine().toCharArray();
        }

        visited = new boolean[n][n];
        int normalCnt = 0, sekyakCnt = 0;
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    bfs(i, j, arr[i][j]);
                    ++normalCnt;
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(arr[i][j] == 'G') arr[i][j] = 'R';
            }
        }

        visited = new boolean[n][n];
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    bfs(i, j, arr[i][j]);
                    ++sekyakCnt;
                }
            }
        }


        System.out.printf("%d %d", normalCnt, sekyakCnt);
    }

    static void bfs(int xx, int yy, char color) {
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(xx, yy));
        while(!q.isEmpty()) {
            Point p = q.poll();
            if(visited[p.x][p.y]) continue;
            visited[p.x][p.y] = true;

            if(p.x > 0 && arr[p.x-1][p.y] == color) {
                q.add(new Point(p.x-1, p.y));
            }
            if(p.y > 0 && arr[p.x][p.y-1] == color) {
                q.add(new Point(p.x, p.y-1));
            }
            if(p.x < n-1 && arr[p.x+1][p.y] == color) {
                q.add(new Point(p.x+1, p.y));
            }
            if(p.y < n-1 && arr[p.x][p.y+1] == color) {
                q.add(new Point(p.x, p.y+1));
            }
        }
    }
}