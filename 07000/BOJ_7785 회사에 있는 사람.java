// https://www.acmicpc.net/problem/7785
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        HashSet<String> hs = new HashSet<>();
        while(n-->0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            switch(st.nextToken()) {
                case "enter":
                    hs.add(name);
                    break;
                case "leave":
                    hs.remove(name);
                    break;
            }
        }
        
        StringJoiner sj = new StringJoiner("\n");
        hs.stream().sorted(Comparator.reverseOrder()).forEach(sj::add);
        System.out.print(sj);
    }
}