// https://www.acmicpc.net/problem/25305
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        Integer cutline = Arrays.stream(br.readLine().split(" "))
                .map(Integer::valueOf)
                .sorted(Comparator.reverseOrder())
                .skip(k - 1)
                .findFirst()
                .get();

        System.out.println(cutline);
    }
}
