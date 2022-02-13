// https://www.acmicpc.net/problem/2358
import java.io.*;
import java.util.*;

public class Main
{
    static HashMap<Integer,Integer> pointX = new HashMap<Integer,Integer>();
    static HashMap<Integer,Integer> pointY = new HashMap<Integer,Integer>();
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

		int n = Integer.parseInt(br.readLine());
		
        for(int i = 0; i < n; ++i)
        {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            
            if(pointX.containsKey(x)) pointX.put(x, pointX.get(x) + 1);
            else pointX.put(x, 1);
            if(pointY.containsKey(y)) pointY.put(y, pointY.get(y) + 1);
            else pointY.put(y, 1);
        }

        int answer = 0;
        Iterator<Integer>  keys = pointX.keySet().iterator();
        while(keys.hasNext()){
            int val = pointX.get(keys.next());
            if(val > 1) answer += 1;
        }
        
        keys = pointY.keySet().iterator();
        while(keys.hasNext()){
            int val = pointY.get(keys.next());
            if(val > 1) answer += 1;
        }
        
        System.out.println(answer);
		return;
	}
}
