// https://www.acmicpc.net/problem/17413
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder tmpSB = new StringBuilder();
        StringBuilder resultSB = new StringBuilder();

        char[] original = br.readLine().toCharArray();

        boolean inTag = false;

        for(char c : original) {
            if(c == '<') {
                inTag = true;
                resultSB.append(tmpSB.reverse());
                resultSB.append(c);
                tmpSB = new StringBuilder();
            }
            else if(c == '>') {
                resultSB.append(c);
                inTag = false;
            }
            else if(c == ' ' && !inTag){
                resultSB.append(tmpSB.reverse()).append(' ');
                tmpSB = new StringBuilder();
            }
            else if(inTag) {
                resultSB.append(c);
            }
            else {
                tmpSB.append(c);
            }
        }

        System.out.println(resultSB.append(tmpSB.reverse()));
    }
}