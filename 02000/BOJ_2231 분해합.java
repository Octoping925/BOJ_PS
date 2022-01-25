// https://www.acmicpc.net/problem/2231
import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		int answer = 0;
		for(int i = Math.max(0, n-70); i < n; ++i)
        {
            if(bunhehap(i) == n) {
                answer = i;
                break;
            }
        }
        System.out.println(answer);
		return;
	}

    static int bunhehap(int x){
        int sum = x;
        while(x>0){
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
}
