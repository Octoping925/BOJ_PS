// https://www.acmicpc.net/problem/2812
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        char[] num = br.readLine().toCharArray();

        int idx = 0;
        int firstMaxIdx;

        while(k > 0) {
            System.out.printf("find, idx=%d\n", idx);
            firstMaxIdx = idx;

            for(int i = idx+1; i < Math.min(k+idx+1, n); ++i) {
                if(num[i] > num[firstMaxIdx]) {
                    firstMaxIdx = i;
                }
            }

            if(firstMaxIdx == idx) {
                System.out.printf("!fmi = %d, idx = %d\n", firstMaxIdx, idx);
                idx++;
            }
            else {
                System.out.printf("fmi = %d, idx = %d\n", firstMaxIdx, idx);

                for(int i = idx; i < firstMaxIdx; ++i) {
                    num[i] = '*';
                }

                k -= firstMaxIdx-idx;
                idx += firstMaxIdx-idx;
            }

            System.out.println(num);
            System.out.println();

            if(idx > n) break;
        }

    }
}