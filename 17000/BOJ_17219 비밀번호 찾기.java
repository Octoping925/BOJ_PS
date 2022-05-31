// https://www.acmicpc.net/problem/17219
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)  throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        HashMap<String, String> hm = new HashMap<>();
        while(n-->0) {
            st = new StringTokenizer(br.readLine());
            hm.put(st.nextToken(), st.nextToken());
        }

        StringBuilder answer = new StringBuilder();
        while(m-->0) {
            answer.append(hm.get(br.readLine())).append("\n");
        }

        System.out.println(answer);
    }
}