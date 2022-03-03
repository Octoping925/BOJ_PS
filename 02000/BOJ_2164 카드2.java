// https://www.acmicpc.net/problem/2164
import java.io.*;
import java.util.*;

public class Main
{
    static Queue<Integer> q = new LinkedList<Integer>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        for(int i = 1; i <= n; ++i) {
            q.add(i);
        }

        while(q.size() > 1)
        {
            q.poll();
            q.add(q.peek());
            q.poll();
        }
        System.out.println(q.peek());
        return;
    }
}
