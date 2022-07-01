import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        while(n-->0){
            int score = 0;
            char[] str = br.readLine().toCharArray();

            for(char c : str) {
                if(c != ' ') {
                    score += c - 'A' + 1;
                }
            }

            System.out.println(score == 100 ? "PERFECT LIFE" : Integer.toString(score));
        }
    }
}