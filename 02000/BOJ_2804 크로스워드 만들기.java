// https://www.acmicpc.net/problem/2804
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");

        char[] str1 = str[0].toCharArray();
        char[] str2 = str[1].toCharArray();

        int idx1 = 0, idx2 = 0;
        boolean isFind = false;
        for(int i = 0; i < str1.length; ++i) {
            if(isFind) break;
            for(int j = 0; j < str2.length; ++j) {
                if(str1[i] == str2[j]) {
                    idx1 = i;
                    idx2 = j;
                    isFind = true;
                    break;
                }
            }
        }
        for(int i = 0; i < str2.length; ++i) {
            for (int j = 0; j < str1.length; ++j) {
                if (i == idx2) System.out.print(str1[j]);
                else if(j == idx1) System.out.print(str2[i]);
                else System.out.print(".");
            }
            System.out.println();
        }
    }
}