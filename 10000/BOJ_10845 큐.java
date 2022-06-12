// https://www.acmicpc.net/problem/10845
import java.io.*;
import java.util.*;

public class Main {
    static final Integer ERR_CODE = -1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        LinkedList<Integer> q = new LinkedList<>();
        while(n-->0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            switch(st.nextToken()) {
                case "push":
                    q.add(Integer.parseInt(st.nextToken()));
                    break;
                case "pop":
                    System.out.println(!q.isEmpty() ? q.poll() : ERR_CODE);
                    break;
                case "size":
                    System.out.println(q.size());
                    break;
                case "empty":
                    System.out.println(q.isEmpty() ? 1 : 0);
                    break;
                case "front":
                    System.out.println(!q.isEmpty() ? q.peekFirst() : ERR_CODE);
                    break;
                case "back":
                    System.out.println(!q.isEmpty() ? q.peekLast() : ERR_CODE);
                    break;
            }
        }
    }
}