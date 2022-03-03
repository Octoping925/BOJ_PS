// https://www.acmicpc.net/problem/11651
import java.io.*;
import java.util.*;

class Point implements Comparable<Point>
{
    private int x, y;
    public Point(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public int getX() { return x; }
    public int getY() { return y; }

    @Override
    public int compareTo(Point l)
    {
        if(y != l.getY()) return Integer.compare(y, l.getY());
        return Integer.compare(x, l.getX());
    }

    @Override
    public String toString()
    {
        return Integer.toString(x) + " " + Integer.toString(y);
    }
}

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        ArrayList<Point> arr = new ArrayList<Point>();
        
        for(int i = 0; i < n; ++i)
        {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            arr.add(new Point(x, y));
        }

        Collections.sort(arr);

        for(Point i : arr)
            System.out.println(i.toString());

        return;
    }
}
