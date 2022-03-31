// https://www.acmicpc.net/problem/11478
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String n = br.readLine();
        HashMap<String, Boolean> hm = new HashMap<>();

        int len = 0;
        for(int i = 0; i < n.length(); ++i){
            StringBuilder sb = new StringBuilder();
            for(int j = i; j < n.length(); ++j) {
                sb.append(n.charAt(i));
                hm.put(sb.toString());
            }
        }

        System.out.println(hm.size());
    }
}