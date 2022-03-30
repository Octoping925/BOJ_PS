// https://www.acmicpc.net/problem/1158
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] st = br.readLine().split(" ");
        int n = Integer.parseInt(st[0]);
        int k = Integer.parseInt(st[1]);

        ArrayList<Integer> josephus = new ArrayList<>();
        for(int i = 1; i <= n; ++i) josephus.add(i);

        int idx = -1;

        System.out.print("<");
        while(josephus.size() > 0) {
            idx = (idx + k) % josephus.size();
            System.out.printf("%d", josephus.get(idx));
            josephus.remove(idx);
            if(josephus.size() > 0) System.out.print(", ");
            else System.out.print(">");
            --idx;
        }
    }
}