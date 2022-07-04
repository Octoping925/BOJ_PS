// https://www.acmicpc.net/problem/1205
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        LinkedList<Integer> rankList = new LinkedList<>();
        
        int n = Integer.parseInt(st.nextToken());
        int score = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());

        if (n > 0) {
            Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt)
                .forEach(rankList::add);
        }

        if(n == p && score <= rankList.getLast()){
            System.out.println(-1);
        } else {
            long result = rankList.stream()
                .filter(x -> x > score)
                .count() + 1;

            System.out.println(result);
        }
    }
}