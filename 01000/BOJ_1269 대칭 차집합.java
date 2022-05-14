// https://www.acmicpc.net/problem/1269
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Set<Integer> a = new HashSet<>();
        Set<Integer> b = new HashSet<>();
        Set<Integer> aa = new HashSet<>();
        Set<Integer> bb = new HashSet<>();

        st = new StringTokenizer(br.readLine(), " ");
        while(st.hasMoreTokens()) {
            int s = Integer.parseInt(st.nextToken());
            a.add(s);
            aa.add(s);
        }

        st = new StringTokenizer(br.readLine(), " ");
        while(st.hasMoreTokens()) {
            int s = Integer.parseInt(st.nextToken());
            b.add(s);
            bb.add(s);
        }

        for (int k : a) {
            bb.remove(k);
        }
        for (int k : b) {
            aa.remove(k);
        }
        aa.addAll(bb);
        System.out.print(aa.size());
    }
}