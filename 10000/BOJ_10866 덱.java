// https://www.acmicpc.net/problem/10866
import java.io.*;
import java.util.*;

public class Main {
    static Integer ERRCODE = -1;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Deque<Integer> dq = new ArrayDeque<>();
        while(n-->0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            switch (st.nextToken()) {
                case "push_front":
                    dq.addFirst(Integer.parseInt(st.nextToken()));
                    break;
                case "push_back":
                    dq.addLast(Integer.parseInt(st.nextToken()));
                    break;
                case "pop_front":
                    System.out.println(!dq.isEmpty() ? dq.pollFirst() : ERRCODE);
                    break;
                case "pop_back":
                    System.out.println(!dq.isEmpty() ? dq.pollLast() : ERRCODE);
                    break;
                case "size":
                    System.out.println(dq.size());
                    break;
                case "empty":
                    System.out.println(dq.isEmpty() ? 1 : 0);
                    break;
                case "front":
                    System.out.println(!dq.isEmpty() ? dq.getFirst() : ERRCODE);
                    break;
                case "back":
                    System.out.println(!dq.isEmpty() ? dq.getLast() : ERRCODE);
                    break;
            }
        }
    }
}