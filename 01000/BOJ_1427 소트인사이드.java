// https://www.acmicpc.net/problem/1427
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String n = br.readLine();
        ArrayList<Character> k = new ArrayList<>();
        
        for(char i : n.toCharArray()) {
            k.add(i);
        }
        
        Collections.sort(k, Collections.reverseOrder());
        
        for(char i : k) {
            System.out.print(i);
        }
        
        return;
    }
}
