// https://www.acmicpc.net/problem/16171
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String txt = br.readLine().chars()
                .filter(x -> x > '9')
                .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
                .toString();

        String original = br.readLine();

        System.out.println(txt.contains(original) ? 1 : 0);
    }
}