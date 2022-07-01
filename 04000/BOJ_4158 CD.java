// https://www.acmicpc.net/problem/4158
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true){
            StringTokenizer st = new StringTokenizer(br.readLine());

            int sg = Integer.parseInt(st.nextToken());
            int sy = Integer.parseInt(st.nextToken());

            if(sg + sy == 0) break;

            HashSet<Integer> hs = new HashSet<>();
            int answer = 0;

            while(sg-->0) {
                hs.add(Integer.parseInt(br.readLine()));
            }

            while(sy-->0) {
                if(hs.contains(Integer.parseInt(br.readLine()))) {
                    answer++;
                }
            }

            sb.append(answer).append("\n");
        }

        System.out.println(sb);
    }
}