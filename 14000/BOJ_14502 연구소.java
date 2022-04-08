// https://www.acmicpc.net/problem/14502
import java.io.*;
import java.util.*;

class Point {
    public int x, y;
    Point(int xx, int yy) {
        x = xx;
        y = yy;
    }
    boolean isSame(int pos, int width) {
        int xx = (pos-1) / width + 1;
        int yy = (pos-1) % width + 1;
        return x == xx && y == yy;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] map = new int[n+1][m+1];
        ArrayList<Point> enemy = new ArrayList<>();
        int blank = n * m;
        
        for(int i = 1; i <= n; ++i) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= m; ++j) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] == 1) {
                    blank--;
                }
                else if(map[i][j] == 2) {
                    enemy.add(new Point(i, j));
                }
            }
        }

        int max = 0;
        // 주소 = map[i/n + 1][j%n + 1];  ex. (5,5)  7  -> (2,2)
        for(int i = 1; i <= n * m; ++i) {
            if(map[(i-1) / m + 1][(i-1) % m + 1] != 0) continue;
            
            for (int j = i+1; j <= n * m; ++j) {
                if(map[(j-1) / m + 1][(j-1) % m + 1] != 0) continue;
                
                for (int k = j+1; k <= n * m; ++k) {
                    if(map[(k-1) / m + 1][(k-1) % m + 1] != 0) continue;

                    Queue<Point> q = new LinkedList<>(enemy);
                    boolean[][] visited = new boolean[n+1][m+1];

                    int safeZoneCnt = blank-3;
                    while(!q.isEmpty()) {
                        Point p = q.poll();
                        if(visited[p.x][p.y] || p.isSame(i, m) || p.isSame(j, m) || p.isSame(k, m)) {
                            continue;
                        }
                        safeZoneCnt--;
                        visited[p.x][p.y] = true;

                        if(p.x > 1 && map[p.x-1][p.y] == 0) {
                            q.add(new Point(p.x-1, p.y));
                        }
                        if(p.y > 1  && map[p.x][p.y-1] == 0) {
                            q.add(new Point(p.x, p.y - 1));
                        }
                        if(p.x < n && map[p.x+1][p.y] == 0) {
                            q.add(new Point(p.x+1, p.y));
                        }
                        if(p.y < m && map[p.x][p.y+1] == 0) {
                            q.add(new Point(p.x, p.y + 1));
                        }
                    }
                    
                    max = Math.max(safeZoneCnt, max);
                }
            }
        }

        System.out.println(max);
    }
}
