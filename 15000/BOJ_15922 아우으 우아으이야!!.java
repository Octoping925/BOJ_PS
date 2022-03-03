// https://www.acmicpc.net/problem/15922
import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        int a, b;
        int left = 0, right = 0;
        int sum = 0;

        for(int i = 0; i < n; ++i) {
            a = sc.nextInt();
            b = sc.nextInt();

            if(i == 0) {
                left = a;
                right = b;
            }
            else {
                if(a > right) {
                    sum += right - left;
                    left = a;
                    right = b;
                }
                else right = Math.max(b, right);
            }
        }

        System.out.println(sum + right - left);
    }
}
