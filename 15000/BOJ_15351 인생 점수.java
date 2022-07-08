// https://www.acmicpc.net/problem/15351
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        while(n-->0){
            int score = br.readLine().chars()
                .filter(x-> x != ' ')
                .map(x -> x-'A'+1)
                .sum();

            System.out.println(score == 100 ? "PERFECT LIFE" : Integer.toString(score));
        }
    }
}