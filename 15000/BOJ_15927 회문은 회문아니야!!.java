// https://www.acmicpc.net/problem/15927
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] txt = br.readLine().toCharArray();

        int maxLen = 1;
        for(int i = 0; i < txt.length; ++i) // 0123215 0123315 12331
        {
            int curLen = 0;
            for(int j = maxLen + 1; j <= txt.length - 1; ++j)
            {
                if(txt[i + txt.length - 1 - j] != txt[j]) {
                    //curLen = j - i + 1;
                    curLen = j - i + 1;
                    break;
                }
            }
            if(curLen > maxLen) maxLen = curLen;
        }
        System.out.println(maxLen > 1 ? maxLen : -1);
    }
}
