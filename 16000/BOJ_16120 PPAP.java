// https://www.acmicpc.net/problem/16120
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] txt = br.readLine().toCharArray();
        char[] ppap = {'P','P','A','P'};

        char[] stack = new char[txt.length + 1];
        int ppap_idx = 0, top = -1;

        for(int i = 0; i < txt.length; ++i) {
            stack[++top] = txt[i];

            if(stack[top] == ppap[ppap_idx]) {
                ++ppap_idx;
            }
            else {
                if(stack[top] == 'P') {
                    if(stack[top-1] == 'P') ppap_idx = 2;
                    else ppap_idx = 1;
                }
                else ppap_idx = 0;
            }

            if(ppap_idx == 4) {
                top -= 3; // PAP
                if(top > 0 && stack[top - 1] == 'P') {
                    ppap_idx = 2;
                }
                else ppap_idx = 1;
            }
        }

        if(top == 0 && stack[top] == 'P') {
            System.out.println("PPAP");
        }
        else {
            System.out.println("NP");
        }
    }
}