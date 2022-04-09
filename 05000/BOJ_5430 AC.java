// https://www.acmicpc.net/problem/5430
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t < T; ++t) {
            char[] p = br.readLine().toCharArray();
            int len = Integer.parseInt(br.readLine());
            String[] arr = new String[len];

            StringTokenizer st = new StringTokenizer(br.readLine(), ",[]");
            for(int i = 0; i < len; ++i) {
                arr[i] = st.nextToken();
            }

            int left = 0, right = len - 1;
            boolean order = true; // 정상순서
            boolean sw = true;

            for(char c : p) {
                if(c == 'R') {
                    order = !order;
                }
                else { // c == 'D'
                    if(left > right) {
                        sw = false;
                        break;
                    }
                    if(order) left++;
                    else right--;
                }
            }

            if(sw) {
                StringJoiner answer = new StringJoiner(",", "[", "]");
                if(order){
                    for(int i = left; i <= right; i++) {
                        answer.add(arr[i]);
                    }
                }
                else{
                    for(int i = right; i >= left; i--) {
                        answer.add(arr[i]);
                    }
                }
                System.out.println(answer);
            }
            else {
                System.out.println("error");
            }
        }
    }
}
