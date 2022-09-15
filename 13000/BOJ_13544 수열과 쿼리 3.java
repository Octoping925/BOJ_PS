// https://www.acmicpc.net/problem/13544
import java.io.*;
import java.util.*;

public class Main {

    static ArrayList<Integer>[] segtree;
    static int[] a;

    public static ArrayList<Integer> init(int left, int right, int node) {
        if (left == right) {
            segtree[node] = new ArrayList<>();
            segtree[node].add(a[left]);
            return segtree[node];
        }
        int mid = (left + right) / 2;
        return segtree[node] = merge(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));
    }

    public static ArrayList<Integer> merge(ArrayList<Integer> left, ArrayList<Integer> right) {
        ArrayList<Integer> rtnArr = new ArrayList<>();
        int x = 0, y = 0;
        while (x < left.size() && y < right.size()) {
            if (left.get(x) <= right.get(y)) {
                rtnArr.add(left.get(x++));
            } else {
                rtnArr.add(right.get(y++));
            }
        }
        while (x < left.size()) {
            rtnArr.add(left.get(x++));
        }
        while (y < right.size()) {
            rtnArr.add(right.get(y++));
        }
        return rtnArr;
    }

    public static int getAnswer(int start, int end, int node, int left, int right, int k) {
        if(right < start || left > end) return 0;
        if(left <= start && end <= right) {
            return segtree[node].size() - upperBound(segtree[node], k);
        }
        int mid = (start + end) / 2;
        return getAnswer(start, mid, node*2, left, right, k) + getAnswer(mid+1, end, node*2 + 1, left, right, k);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        a = new int[n+1];
        segtree = new ArrayList[n * 5];

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 1; i <= n; ++i) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        init(1, n, 1);

        int k = Integer.parseInt(br.readLine());
        int lastAnswer = 0;
        while (k-- > 0) {
            String[] command = br.readLine().split(" ");
            lastAnswer = getAnswer(1, n, 1, Integer.parseInt(command[0]) ^ lastAnswer, Integer.parseInt(command[1]) ^ lastAnswer, Integer.parseInt(command[2]) ^ lastAnswer);
            bw.write(Integer.toString(lastAnswer));
            bw.newLine();
        }
        bw.flush();
    }

    public static int upperBound(ArrayList<Integer> arr, int target) {
        int st = 0, end = arr.size();
        while(st < end) {
            int mid = (st + end) / 2;
            if(arr.get(mid) > target) end = mid;
            else st = mid + 1;
        }
        return end;
    }
}