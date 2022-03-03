// https://www.acmicpc.net/problem/2206
import java.io.*;
import java.util.*;

public class Main
{
    static Queue<Point> visit0 = new LinkedList<Point>();
    static Queue<Point> visit1 = new LinkedList<Point>();
    static char[][] map;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        map = new char[n + 1][m + 1];

        for(int i = 1; i < n; ++i)
        {
            st = new StringTokenizer(br.readLine(), "");
            for(int j = 1; j < m; ++j)
                map[i][j] = Integer.parseInt(st.nextToken());
        }

        visit0.put(Point(x, y));

        while()
        return;
    }
}

public class Point
{
    public int x, y;
    Point(int a, int b) { 
        x = a;
        y = b;
    }
}
