// https://www.acmicpc.net/problem/2170
import java.io.*;
import java.util.*;

class Line {
    int left, right;
    public Line(int l, int r) {
        this.left = l;
        this.right = r;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        List<Line> arr = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            arr.add(new Line(l, r));
        }

        arr.sort(Comparator.comparingInt(a -> a.left));

        long sum = 0;
        int left = 0, right = 0, sw = 0;

        for(Line line : arr) {
            int ll = line.left, rr = line.right;
            if(sw == 0) {
                left = ll;
                right = rr;
                sw = 1;
            }
            if(ll > right) {
                sum += right - left;
                left = ll;
                right = rr;
            }
            else right = Math.max(rr, right);
        }

        System.out.println(sum + right - left);
    }
}
