// https://www.acmicpc.net/problem/1543
import java.io.*;

public class Main {
    public static void main(String[] args)  throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String doc = br.readLine();
        String searchWord = br.readLine();

        int cnt = 0;
        while(doc.contains(searchWord)) {
            doc = doc.replaceFirst(searchWord, "!");
            ++cnt;
        }

        System.out.print(cnt);
    }
}