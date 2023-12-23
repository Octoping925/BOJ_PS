import java.io.*;
import java.util.*;

public class Main {
    static int[][] map = new int[11][10];
    static int r1, c1;
    static int r2, c2;

    public static void main(String[] args) throws IOException {
        init();
        getInput();

        System.out.println(bfs());
    }

    static void init() {
        for (int i = 0; i < 11; ++i)
            for (int j = 0; j < 10; ++j)
                map[i][j] = 110;
    }

    static void getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        r1 = Integer.parseInt(st.nextToken());
        c1 = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        r2 = Integer.parseInt(st.nextToken());
        c2 = Integer.parseInt(st.nextToken());
    }

    static int bfs() {
        Deque<Point> queue = new ArrayDeque<>();
        queue.add(new Point(r1, c1, 0));

        while (!queue.isEmpty()) {
            Point point = queue.pop();

            if (point.isAlreadyVisited())
                continue;

            map[point.x][point.y] = point.count;

            if (point.x == r2 && point.y == c2) {
                return point.count;
            }

            if (point.canGoUpLeft())
                queue.add(point.upLeft());

            if (point.canGoUpRight())
                queue.add(point.upRight());

            if (point.canGoDownLeft())
                queue.add(point.downLeft());

            if (point.canGoDownRight())
                queue.add(point.downRight());

            if (point.canGoLeftUp())
                queue.add(point.leftUp());

            if (point.canGoLeftDown())
                queue.add(point.leftDown());

            if (point.canGoRightUp())
                queue.add(point.rightUp());

            if (point.canGoRightDown())
                queue.add(point.rightDown());
        }

        return -1;
    }
}

class Point {
    int x;
    int y;
    int count;

    public Point(int x, int y, int count) {
        this.x = x;
        this.y = y;
        this.count = count;
    }

    public boolean isAlreadyVisited() {
        return Main.map[x][y] < count;
    }

    public Point upLeft() {
        return new Point(x - 3, y - 2, count + 1);
    }

    public Point upRight() {
        return new Point(x - 3, y + 2, count + 1);
    }
    public Point downLeft() {
        return new Point(x + 3, y - 2, count + 1);
    }

    public Point downRight() {
        return new Point(x + 3, y + 2, count + 1);
    }

    public Point leftUp() {
        return new Point(x - 2, y - 3, count + 1);
    }

    public Point leftDown() {
        return new Point(x + 2, y - 3, count + 1);
    }

    public Point rightUp() {
        return new Point(x - 2, y + 3, count + 1);
    }

    public Point rightDown() {
        return new Point(x + 2, y + 3, count + 1);
    }

    public boolean canGoUpLeft() {
        if (x < 3 || y < 2) return false;
        if (Main.r2 == x - 1 && Main.c2 == y) return false;
        if (Main.r2 == x - 2 && Main.c2 == y - 1) return false;
        return true;
    }

    public boolean canGoUpRight() {
        if (x < 3 || y > 6) return false;
        if (Main.r2 == x - 1 && Main.c2 == y) return false;
        if (Main.r2 == x - 2 && Main.c2 == y + 1) return false;
        return true;
    }

    public boolean canGoDownLeft() {
        if (x > 6 || y < 2) return false;
        if (Main.r2 == x + 1 && Main.c2 == y) return false;
        if (Main.r2 == x + 2 && Main.c2 == y - 1) return false;
        return true;
    }

    public boolean canGoDownRight() {
        if (x > 6 || y > 6) return false;
        if (Main.r2 == x + 1 && Main.c2 == y) return false;
        if (Main.r2 == x + 2 && Main.c2 == y + 1) return false;
        return true;
    }

    public boolean canGoLeftUp() {
        if (x < 2 || y < 3) return false;
        if (Main.r2 == x && Main.c2 == y - 1) return false;
        if (Main.r2 == x - 1 && Main.c2 == y - 2) return false;
        return true;
    }

    public boolean canGoLeftDown() {
        if (x > 7 || y < 3) return false;
        if (Main.r2 == x && Main.c2 == y - 1) return false;
        if (Main.r2 == x + 1 && Main.c2 == y - 2) return false;
        return true;
    }

    public boolean canGoRightUp() {
        if (x < 2 || y > 5) return false;
        if (Main.r2 == x && Main.c2 == y + 1) return false;
        if (Main.r2 == x - 1 && Main.c2 == y + 2) return false;
        return true;
    }

    public boolean canGoRightDown() {
        if (x > 7 || y > 5) return false;
        if (Main.r2 == x && Main.c2 == y + 1) return false;
        if (Main.r2 == x + 1 && Main.c2 == y + 2) return false;
        return true;
    }
}