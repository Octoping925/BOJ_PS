// https://www.acmicpc.net/problem/2206
import java.io.*;
import java.util.*;

class Move {
    public int x, y;
    public int dis;
    public int status;

    Move(int xx, int yy, int di, int st) {
        x = xx;
        y = yy;
        dis = di;
        status = st;
    }
}

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] t = br.readLine().split(" ");
        int n = Integer.parseInt(t[0]);
        int m = Integer.parseInt(t[1]);

        int[][] map = new int[n + 1][m + 1];
        int[][][] dis = new int[n + 1][m + 1][2];

        for (int i = 1; i <= n; ++i) {
            char[] txt = br.readLine().toCharArray();
            for (int j = 1; j <= m; ++j) {
                map[i][j] = txt[j - 1] - '0';
                dis[i][j][0] = dis[i][j][1] = n * m + 1;
            }
        }

        Queue<Move> q = new LinkedList<>();
        q.add(new Move(1, 1, 1, 0));
        while (!q.isEmpty()) {
            Move mo = q.poll();
            mo.status += map[mo.x][mo.y];
            if (mo.status == 2) continue;

            if (mo.status == 1 && mo.dis >= dis[mo.x][mo.y][0]) {
                continue;
            }
            if (mo.dis >= dis[mo.x][mo.y][mo.status]) {
                continue;
            }
            dis[mo.x][mo.y][mo.status] = mo.dis;

            if (mo.x == n && mo.y == m) continue;

            if (mo.x > 1) {
                q.add(new Move(mo.x - 1, mo.y, mo.dis + 1, mo.status));
            }
            if (mo.y > 1) {
                q.add(new Move(mo.x, mo.y - 1, mo.dis + 1, mo.status));
            }
            if (mo.x < n) {
                q.add(new Move(mo.x + 1, mo.y, mo.dis + 1, mo.status));
            }
            if (mo.y < m) {
                q.add(new Move(mo.x, mo.y + 1, mo.dis + 1, mo.status));
            }
        }

        int answer = Math.min(dis[n][m][0], dis[n][m][1]);
        System.out.println(answer != n * m + 1 ? answer : -1);

    }
}
