// https://www.acmicpc.net/problem/20419
import java.io.*;
import java.util.*;

class Scroll {
    public int L;
    public int R;
    Scroll(int l, int r) { L = l; R = r; }
    int getTotal() { return Math.max(L, R); }
    Scroll useL() { return new Scroll(L+1, R); }
    Scroll useR() { return new Scroll(L, R+1); }
}

class Point {
    public int x;
    public int y;
    Point(int xx, int yy) { x = xx; y = yy; }

    Point goForward(char dir) {
        if(dir == 'U') return new Point(x-1, y);
        else if(dir == 'D') return new Point(x+1, y);
        else if(dir == 'L') return new Point(x, y-1);
        else return new Point(x, y+1);
    }
}

public class Main {

    static char[][] maze;
    static boolean[][] visited;
    static Scroll[][] chk;
    static int n, m, k;
    static boolean ABLE = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        maze = new char[n+1][m+1];
        chk = new Scroll[n+1][m+1];

        for(int i = 1; i <= n; ++i) {
            String str = br.readLine();
            for(int j = 1; j <= m; ++j) {
                maze[i][j] = str.charAt(j-1);
            }
        }

        dfs(new Point(1, 1), new Scroll(0, 0));
        System.out.print(ABLE ? "Yes" : "NO");
    }

    static char turnLeft(char dir) {
        switch(dir){
            case 'U':
                return 'L';
            case 'D':
                return 'R';
            case 'L':
                return 'D';
            case 'R':
            default:
                return 'U';
        }
    }
    static char turnRight(char dir) {
        return turnLeft(turnLeft(turnLeft(dir)));
//        switch(dir){
//            case 'U':
//                return 'L';
//            case 'D':
//                return 'R';
//            case 'L':
//                return 'D';
//            case 'R':
//                return 'U';
//        }
    }

    static void dfs(Point p, Scroll sc) {
        if(sc.getTotal() > k) return;

        int x = p.x, y = p.y;
        if(chk[x][y] != null && chk[x][y].getTotal() == 0) return;
        if(x == n && y == m) {
            ABLE = true;
            return;
        }
        if(chk[x][y] == null) chk[x][y] = sc;
        dfs(p.goForward(maze[x][y]), sc); // 주어진 방향 그대로






    }
}

// 미완