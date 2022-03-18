// https://www.acmicpc.net/problem/1062 
import java.io.*;
import java.util.*;

public class Main
{
    static String words[];
    static int bitmask[];
    static int allbitmask[];
    static int n, k, max;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine(), " ");

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        
        if(k < 5) {
            System.out.println("0");
            return;
        }

        bitmask = new int[n];
        allbitmask = new int[26];
        words = new String[n];
        int useNum = 0;
        for(int i = 0; i < n; ++i) {
            String str = br.readLine();
            words[i] = str;
            for(char j : str.toCharArray()) {
                bitmask[i] = bitadd(bitmask[i], j);
                if(allbitmask[j - 'a'] == 0) {
                    ++allbitmask[j - 'a'];
                    ++useNum;
                }
                
            }
        }

        if(useNum <= k) {
            System.out.println(n);
            return;
        }

        int word = 0;
        word = bitadd(word, 'a');
        word = bitadd(word, 'n');
        word = bitadd(word, 't');
        word = bitadd(word, 'i');
        word = bitadd(word, 'c');
        back(5, word);
        System.out.println(max);
        return;
    }

    static void back(int cnt, int word) {
        if(cnt == k) {
            System.out.println("learned: " + bittoString(word));
            int sum = 0;
            for(int i = 0; i < n; ++i) {
                if(isbitbigger(word, bitmask[i])) {
                    sum++;
                    System.out.println(words[i]);
                }
            }
            if(sum > max) max = sum;
            System.out.println(sum);
            System.out.println();
            return;
        }

        for(int i = 0; i < 26; ++i)
        {
            if(allbitmask[i] == 1 && (word & (1 << i)) == 0)
                back(cnt + 1, bitadd(word, i));
        }
    }

    static int bitadd(int x, int add) {
        return x | (1 << add);
    }
    static int bitadd(int x, char add) {
        return x | (1 << (add - 'a'));
    }
    static String bittoString(int bit) {
        String k = "";
        for(int i = 0; i < 26; ++i) {
            if((bit & (1 << i)) > 0) k += (char)(i + 'a');
        }
        return k;
    }
    static boolean isbitbigger(int bit1, int bit2) {
        return (bit1 & bit2) == bit2;
    }
}
