// https://www.acmicpc.net/problem/2204
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true) {
            int n = Integer.parseInt(br.readLine());
            if(n == 0) break;

            String[] arr = new String[n];
            for(int i = 0; i < n; ++i) {
                arr[i] = br.readLine();
            }

            Arrays.stream(arr)
                .sorted(Comparator.comparing(String::toUpperCase))
                .limit(1)
                .forEach(System.out::println);
        }
    }
}