// https://www.acmicpc.net/problem/14425
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        HashMap<String, Boolean> hm = new HashMap<>();

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        while(n-->0) {
            hm.put(br.readLine(), true);
        }

        int cnt = 0;
        while(m-->0) {
            if(hm.containsKey(br.readLine())) cnt++;
        }

        System.out.print(cnt);
    }
}