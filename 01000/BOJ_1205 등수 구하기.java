// https://www.acmicpc.net/problem/1205
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        LinkedList<Integer> rankList = new LinkedList<>();
        int[] user = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        if (user[0] > 0) {
            Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt)
                .forEach(rankList::add);
        }

        if(user[0] == user[2] && user[1] <= rankList.getLast()){
            System.out.println(-1);
        } else {
            long result = rankList.stream()
                .filter(x -> x > user[1])
                .count() + 1;

            System.out.println(result);
        }
    }
}