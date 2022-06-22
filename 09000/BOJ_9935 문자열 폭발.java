// https://www.acmicpc.net/problem/9935
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] txt = br.readLine().toCharArray();
        char[] explode = br.readLine().toCharArray();

        char[] stack = new char[1000010];
        int top = -1;
        int explode_idx = 0;

        for(char c : txt) {
            stack[++top] = c;

            if(stack[top] == explode[explode_idx]) {
                ++explode_idx;
            }
            else {
                explode_idx = 0;
                if(stack[top] == explode[0]) {
                    explode_idx++;
                }
            }

            if(explode_idx == explode.length) {
                top -= explode.length;
                explode_idx = 0;

                if(top > -1) {
                    for(int i = Math.max(top-explode.length, 0); i <= top; ++i) {
                        if(stack[i] == explode[explode_idx]) {
                            explode_idx++;
                        }
                        else {
                            explode_idx = stack[i] == explode[0] ? 1 : 0;
                        }
                    }
                }
            }
        }

        if(top == -1) {
            System.out.println("FRULA");
        }
        else {
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i <= top; ++i) {
                sb.append(stack[i]);
            }
            System.out.println(sb);
        }
    }
}