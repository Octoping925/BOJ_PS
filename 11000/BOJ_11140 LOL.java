// https://www.acmicpc.net/problem/11140
import java.io.*;
import java.util.regex.Pattern;

public class Main {

    public static int solution(String str){
        if(str.contains("lol")) return 0;
        else if(str.contains("lo") || str.contains("ol") || str.contains("ll")) return 1;
        else if(!str.contains("l") && !str.contains("o")) return 3;
        else if(Pattern.matches(".*l.l.*", str)) return 1;
        return 2;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        while(n-->0) {
            System.out.println(solution(br.readLine()));
        }
    }
}