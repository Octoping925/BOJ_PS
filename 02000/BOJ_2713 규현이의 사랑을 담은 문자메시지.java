// https://www.acmicpc.net/problem/2713
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while(t-->0) {
            String[] st = br.readLine().split(" ");
            int r = Integer.parseInt(st[0]);
            int c = Integer.parseInt(st[1]);

            StringBuilder sb = new StringBuilder();
            for(int i = 2; i < st.length; ++i) {;
                sb.append(st[i]).append(" ");
            }
            String txt = makeBinaryString(sb.substring(0, Math.max(sb.length() - 1, 0)), r * c);
            System.out.println(makeSnail(txt, r, c));
        }
    }

    static String makeBinaryString(String txt, int length) {
        StringBuilder sb = new StringBuilder();
        for(char i : txt.toCharArray()) {
            if(i == ' ') sb.append(makeFiveBinary(0));
            else sb.append(makeFiveBinary(i - 'A' + 1));
        }
        while(sb.length() < length) {
            sb.append(0);
        }
        return sb.toString();
    }

    static String makeFiveBinary(int num) {
        StringBuilder sb = new StringBuilder();
        Stack<Integer> st = new Stack<>();
        while(num > 0 || st.size() < 5) {
            st.add(num % 2);
            num /= 2;
        }
        while(!st.empty()) {
            sb.append(st.pop());
        }
        return sb.toString();
    }

    static String makeSnail(String txt, int r, int c) {
        char[][] arr = new char[r][c];
        for(int i = 0; i < r; ++i)
            Arrays.fill(arr[i], '*');

        int dir = 0; // 우 하 좌 상
        int x = 0, y = 0;
        for(int i = 0; i < txt.length(); ++i) {
            arr[x][y] = txt.charAt(i);
            if(i == txt.length() - 1) break;

            if(dir == 0) {
                if(y+1 == c || arr[x][y+1] != '*') dir++;
                else ++y;
            }
            if(dir == 1) {
                if(x+1 == r || arr[x+1][y] != '*') dir++;
                else ++x;
            }
            if(dir == 2) {
                if(y == 0 || arr[x][y-1] != '*') dir++;
                else --y;
            }
            if(dir == 3) {
                if(x == 0 || arr[x-1][y] != '*') {
                    dir = 0;
                    i--;
                }
                else --x;
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                sb.append(arr[i][j]);

        return sb.toString();
    }
}