// https://www.acmicpc.net/problem/5568
import java.io.*;
import java.util.*;

public class Main
{
    static HashMap<String,Integer> hm = new HashMap<String,Integer>();
    static String cards[];
    static int visited[];
    static int n, k;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());
        
        cards = new String[n];
        visited = new int[n];
        
        for(int i = 0; i < n; ++i)
            cards[i] = br.readLine();
        
        back("", 0);
        System.out.println(hm.size());
	}
	
	static void back(String num, int depth) {
	    if(depth == k) {
	        hm.put(num, 1);
	        return;
	    }
	    
	    for(int i = 0; i < n; ++i) {
	        if(visited[i] == 0) {
	            ++visited[i];
	            back(num + cards[i], depth + 1);
	            --visited[i];
	        }
	    }
	}
}