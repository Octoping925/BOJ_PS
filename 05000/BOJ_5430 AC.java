// https://www.acmicpc.net/problem/5430
import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
		for(int t = 0; t < T; ++t)
        {
            char p[] = br.readLine().toCharArray();
            int len = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine(), ",[]");
            ArrayList<Integer> arr = new ArrayList<Integer>();

            for(int i = 0; i < len; ++i) {
                arr.add(Integer.parseInt(st.nextToken()));
            }
            

            int left = 0, right = len - 1;
            boolean order = true; // 정상순서
            boolean sw = true;

            for(char c : p)
            {
                if(c == 'R') {
                    order = !order;
                }
                else if(c == 'D') {
                    if(left > right) {
                        sw = false;
                        break;
                    }
                    if(order) left++;
                    else right--;
                }
            }
            
            StringBuilder answer = new StringBuilder();
            if(sw) {
                answer.append("[");
                if(order){
                    for(int i = left; i <= right; i++) {
                        answer.append(arr.get(i));
                        if(i < right) answer.append(",");
                    }
                }
                else{
                    for(int i = right; i >= left; i--) {
                        answer.append(arr.get(i));
                        if(i > left) answer.append(",");
                    }
                }
                answer.append("]");
                
            }
            else answer.append("error");
            
            System.out.println(answer.toString());
        }
	}
}
