.. https://www.acmicpc.net/problem/11508
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            arr.add(Integer.parseInt(br.readLine()));
        }

        arr.sort(Comparator.reverseOrder());

        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if((i+1) % 3 > 0) {
                sum += arr.get(i);
            }
        }

        System.out.println(sum);
    }
}