// https://www.acmicpc.net/problem/16171
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        br.readLine().chars()
                .filter(x -> x > '9')
                .forEach(x -> sb.append((char) x));

        String original = br.readLine();

        System.out.println(sb.toString().contains(original) ? 1 : 0);
    }
}