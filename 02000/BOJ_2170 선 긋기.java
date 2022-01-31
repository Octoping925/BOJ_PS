// https://www.acmicpc.net/problem/2170
import java.io.*;
import java.util.*;

class Line implements Comparable<Line>
{
    private int left;
    private int right;
    public Line(int l, int r)
    {
        left = l;
        right = r;
    }

    public int getLength() { return right - left; }
    public int getLeft() { return left; }
    public int getRight() { return right; }

    @Override
    public int compareTo(Line l)
    {
        return Integer.compare(left, l.getLeft());
    }
}

public class Main
{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

		int n = Integer.parseInt(br.readLine());

        ArrayList<Line> arr = new ArrayList<Line>();
		
        for(int i = 0; i < n; ++i)
        {
            st = new StringTokenizer(br.readLine(), " ");
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            arr.add(new Line(l, r));
        }

        Collections.sort(arr);

        long sum = 0;
        int left = 0, right = 0, sw = 0;
        for(Line i  : arr)
        {
            int ll = i.getLeft(), rr = i.getRight();
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
		return;
	}
}
