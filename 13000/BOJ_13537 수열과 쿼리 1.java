import java.io.*;
import java.util.*;

public class Main {

    static ArrayList<Integer>[] segtree;
    static int[] a;
    static int n;

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
//        while(true) {
//            testFunc();
//        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        a = new int[n+1];
        segtree = new ArrayList[n * 5];

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 1; i <= n; ++i) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        init(1, n, 1);

        int k = Integer.parseInt(br.readLine());
        while (k-- > 0) {
            String[] command = br.readLine().split(" ");
            bw.write(Integer.toString(getAnswer(1, n, 1, Integer.parseInt(command[0]), Integer.parseInt(command[1]), Integer.parseInt(command[2]))));
            bw.newLine();
        }
        
        bw.flush();
        return;
    }

    // public static void testFunc() throws IOException {
    //     Random random = new Random();
    //     n = random.nextInt(100) + 1;
    //     a = new int[n+1];
    //     segtree = new ArrayList[n * 3];
    //     System.out.println(n);
    //     for (int i = 1; i <= n; ++i) {
    //         a[i] = random.nextInt(10) + 1;
    //         System.out.printf("%d ", a[i]);
    //     }
    //     System.out.println();
    //     init(1, n, 1);
    //     int k = random.nextInt(15) + 1;
    //     while (k-- > 0) {
    //         int l = random.nextInt(n)+1;
    //         int r = random.nextInt(n)+1;
    //         int p = random.nextInt(10000);
    //         System.out.printf("%d %d %d\n", l, r, p);
    //         System.out.println(getAnswer(1, n, 1, l, r, p));
    //         System.out.println("---------------------");
    //     }
    // }

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
/*
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2
 */
/*
82
3 1 4 7 5 9 2 9 6 1 4 8 10 10 6 9 5 3 2 1 4 2 9 8 6 2 5 3 10 6 6 8 2 4 4 3 9 8 4 4 4 5 2 4 7 10 6 7 1 9 6 9 6 4 10 7 1 9 9 7 1 4 10 1 2 9 4 8 9 8 9 2 3 5 2 5 2 1 8 10 9 3
*/