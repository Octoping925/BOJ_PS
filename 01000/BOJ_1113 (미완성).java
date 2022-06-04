// https://www.acmicpc.net/problem/1113
import java.io.*;
import java.util.*;

class Point {
    int x, y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main
{
    static int[][] map;
    static boolean[][] visited;
    static int n, m;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n+1][m+1];
        visited = new boolean[n+1][m+1];
        for(int i = 0; i < n; ++i) {
            map[i] = Arrays.stream(br.readLine().split("")).mapToInt(Integer::parseInt).toArray();
        }

        int cnt = 0;
        int answer = 0;
        do {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if(!visited[i][j] && isWrapped(i, j, map[i][j])) {
                        cnt = fill(i, j, map[i][j]);
                        answer += cnt;
                    }
                }
            }
        } while(cnt > 0);

        System.out.println(answer);
    }

    static boolean isWrapped(int x, int y, int val) {
        if(x > 0 && map[x-1][y] == val) {
            isWrapped()
        }
        if(y > 0 && map[x][y-1] == val) {
            q.add(new Point(x, y-1));
        }
        if(x < n-1 && map[x+1][y] == val) {
            q.add(new Point(x+1, y));
        }
        if(y < m-1 && map[x][y+1] == val) {
            q.add(new Point(x, y+1));
        }

        return true;
    }

    static int fill(int x, int y, int val) {
        boolean[][] visited = new boolean[n+1][m+1];

        Queue<Point> q = new LinkedList<>();
        q.add(new Point(x, y));

        int cnt = 0;
        while(!q.isEmpty()) {
            Point p = q.poll();

            if(visited[p.x][p.y]) continue;

            cnt += val - map[p.x][p.y];
            visited[p.x][p.y] = true;
            map[p.x][p.y] = val;

            if(p.x > 0 && map[p.x-1][p.y] == val) {
                q.add(new Point(p.x-1, p.y));
            }
            if(p.y > 0 && map[p.x][p.y-1] == val) {
                q.add(new Point(p.x, p.y-1));
            }
            if(p.x < n-1 && map[p.x+1][p.y] == val) {
                q.add(new Point(p.x+1, p.y));
            }
            if(p.y < m-1 && map[p.x][p.y+1] == val) {
                q.add(new Point(p.x, p.y+1));
            }
        }

        return cnt;
    }
}