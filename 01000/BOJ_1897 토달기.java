// https://www.acmicpc.net/problem/1897
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args)  throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        String originalWord = st.nextToken();

        HashSet<String> dict = new HashSet<>();
        for(int i = 0; i < n; ++i) {
            String word = br.readLine();
            if(word.length() > 3) {
                dict.add(word);
            }
        }

        Queue<String> q = new LinkedList<>();
        q.add(originalWord);

        String maxWord = originalWord;
        while(!q.isEmpty()) {
            maxWord = q.poll();

            for (String key : dict) {
                if (!q.contains(key) && todalgi(maxWord, key)) {
                    q.add(key);
                }
            }
        }

        System.out.print(maxWord);
    }

    static boolean todalgi(String asIs, String toBe) {
        if(asIs.length() + 1 != toBe.length()) {
            return false;
        }

        int defCnt = 0;
        for (int i = 0, j = 0; i < asIs.length() && j < toBe.length() && defCnt <= 1; ++j) {
            if (asIs.charAt(i) != toBe.charAt(j)) {
                defCnt++;
            } else {
                i++;
            }
        }
        return defCnt <= 1;

//        # Wrong Logic 1
//        if(asIs.length() + 1 != toBe.length()) {
//            return false;
//        }
//
//        for(char c : asIs.toCharArray()) {
//            toBe = toBe.replaceFirst(String.valueOf(c), "");
//        }
//
//        return toBe.length() == 1;


//        # Wrong Logic 2
//        if(asIs.length() + 1 != toBe.length()) {
//            return false;
//        }
//        int[] abc = new int[27];
//        int cnt = toBe.length();
//        for(char c : toBe.toCharArray()) {
//            abc[c-'a']++;
//        }
//        for(char c : asIs.toCharArray()) {
//            if(abc[c-'a'] > 0) {
//                abc[c-'a']--;
//                cnt--;
//            }
//        }
//        return cnt == 1;
    }
}