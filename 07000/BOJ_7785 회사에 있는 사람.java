// https://www.acmicpc.net/problem/7785
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        HashSet<String> hs = new HashSet<>();
        while(n-->0) {
            String[] str = br.readLine().split(" ");
            switch(str[1]) {
                case "enter":
                    hs.add(str[0]);
                    break;
                case "leave":
                    hs.remove(str[0]);
                    break;
            }
        }

        hs.stream().sorted(Comparator.reverseOrder()).forEach(System.out::println);
    }
}