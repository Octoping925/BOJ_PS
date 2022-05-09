// https://www.acmicpc.net/problem/1235
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        String[] arr = new String[n];
        for(int i = 0; i < n; ++i) {
            arr[i] = br.readLine();
        }

        HashMap<String, Boolean> hm = new HashMap<>();

        for(int i = 1; i <= arr[0].length(); ++i) {
            boolean sw = true;
            for(String s : arr) {
                String now = s.substring(s.length() - i);
                if(hm.containsKey(now)) {
                    sw = false;
                    break;
                }
                hm.put(now, true);
            }

            if(sw) {
                System.out.println(i);
                return;
            }
        }
    }
}