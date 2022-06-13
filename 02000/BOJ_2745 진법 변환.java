// https://www.acmicpc.net/problem/2745
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        char[] bTypeNum = st.nextToken().toCharArray();
        int powNum = Integer.parseInt(st.nextToken());

        int result = 0;
        int pow = 1;
        for(int i = bTypeNum.length - 1; i >= 0; --i) {
            char c = bTypeNum[i];
            int num = c >= 'A' ? c-'A'+10 : c-'0';

            result += pow * num;
            pow *= powNum;
        }

        System.out.println(result);
    }
}