// https://www.acmicpc.net/problem/25192
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int answer = 0;
        HashSet<String> hs = new HashSet<>();
        while(n-->0) {
            String name = br.readLine();
            if(name.equals("ENTER")) {
                hs.clear();
            }
            else if(!hs.contains(name)) {
                hs.add(name);
                ++answer;
            }
        }

        System.out.println(answer);
    }
}