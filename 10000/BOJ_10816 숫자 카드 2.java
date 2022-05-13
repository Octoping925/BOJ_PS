// https://www.acmicpc.net/problem/10816
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        HashMap<String, Integer> hm = new HashMap<>();

        int n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine(), " ");
        while(st.hasMoreTokens()) {
            String s = st.nextToken();
            hm.put(s, hm.get(s) == null ? 1 : hm.get(s) + 1);
        }

        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine(), " ");

        StringBuilder str = new StringBuilder();
        while(st.hasMoreTokens()) {
            String p = st.nextToken();
            str.append(hm.get(p) == null ? 0 : hm.get(p)).append(' ');
        }

        System.out.print(str);
    }
}