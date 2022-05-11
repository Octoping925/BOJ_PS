// https://www.acmicpc.net/problem/10815
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        HashMap<String, Boolean> hm = new HashMap<>();

        int n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine(), " ");
        while(st.hasMoreTokens()) {
            hm.put(st.nextToken(), true);
        }

        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine(), " ");

        StringBuilder str = new StringBuilder();
        while(st.hasMoreTokens()) {
            str.append(hm.containsKey(st.nextToken()) ? 1 : 0).append(' ');
        }

        System.out.print(str);
    }
}