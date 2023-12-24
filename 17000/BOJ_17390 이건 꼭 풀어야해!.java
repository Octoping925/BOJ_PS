// https://www.acmicpc.net/problem/17390
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        int[] prefixSum = new int[n+1];
        prefixSum[0] = arr[0];
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i-1] + arr[i-1];
        }

        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            bw.write(Integer.toString(prefixSum[end] - prefixSum[start - 1]));
            bw.newLine();
        }

        bw.flush();
    }
}
