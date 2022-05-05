// https://www.acmicpc.net/problem/1551
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] arr = Arrays.stream(br.readLine().split(","))
                          .mapToInt(Integer::parseInt)
                          .toArray();

        for(int i = 1; i <= k; ++i) {
            for(int j = 0; j < n-i; ++j) {
                arr[j] = arr[j+1]-arr[j];
            }
        }

        StringJoiner sj = new StringJoiner(",");
        for(int j = 0; j < n-k; ++j) {
            sj.add(Integer.toString(arr[j]));
        }
        System.out.print(sj);
    }
}