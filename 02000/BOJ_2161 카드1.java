// https://www.acmicpc.net/problem/2161
import java.io.*;
import java.util.*;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());

        List<Integer> trash = new ArrayList<>(n);
        Deque<Integer> queue = new ArrayDeque<>(n);

        for(int i = 1; i <= n; ++i) {
            queue.add(i);
        }

        while(queue.size() > 1) {
            trash.add(queue.removeFirst());
            queue.addLast(queue.removeFirst());
        }

        for (Integer integer : trash) {
            System.out.print(integer + " ");
        }
        System.out.print(queue.removeFirst());
    }
}
