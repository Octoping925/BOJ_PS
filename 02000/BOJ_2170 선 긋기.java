// https://www.acmicpc.net/problem/2170
import java.io.*;
import java.util.*;

class Line implements Comparable<Line> {
    public int left;
    public int right;

    public Line(int l, int r) {
        left = l;
        right = r;
    }

    public int getLength() {
        return right - left;
    }
    public void set(Line l) {
        left = l.left;
        right = l.right;
    }

    @Override
    public int compareTo(Line l) {
        return Integer.compare(left, l.left);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Line[] arr = new Line[n];

        for(int i = 0; i < n; ++i) {
            String[] st = br.readLine().split(" ");
            int l = Integer.parseInt(st[0]);
            int r = Integer.parseInt(st[1]);
            arr[i] = new Line(l, r);
        }

        Arrays.sort(arr);

        long sum = 0;
        Line l = new Line(0, 0);
        boolean first = true;
        for(Line i : arr) {
            if(first) {
                l.set(i);
                first = false;
            }
            if(i.left > l.right) {
                sum += l.getLength();
                l.set(i);
            }
            else l.right = Math.max(i.right, l.right);
        }

        System.out.println(sum + l.getLength());
    }
}
