// https://www.acmicpc.net/problem/1158
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    void solution (int N, int K) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        Boolean[] booleanArr = new Boolean[N+1];
        Arrays.fill(booleanArr, true);

        int nowIndex = -1;
        int result = 0;

        sb.append("<");
        while (result < N) {
            int count = 0;
            while (count < K){
                nowIndex = (nowIndex + 1) % N;
                if(booleanArr[nowIndex]){
                    count++;
                }
            }

            sb.append(nowIndex + 1);
            if(++result < N) sb.append(", ");
            else sb.append(">");
            booleanArr[nowIndex] = false;
        }

        bw.write(sb.toString());
        bw.flush();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int N = Integer.parseInt(st.nextToken()); //인원수
        int K = Integer.parseInt(st.nextToken()); //지울대상의 번째

        Main main = new Main();
        main.solution(N,K);
    }

}