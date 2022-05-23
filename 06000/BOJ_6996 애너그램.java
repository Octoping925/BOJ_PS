// https://www.acmicpc.net/problem/6996
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    private static boolean solveAnagrams(String first, String second ) {
        /* ------------------- INSERT CODE HERE --------------------
         *
         * Your code should return true if the two strings are anagrams of each other.
         *
         * */
        int[] abc = new int[26];
        int cnt = first.length();
        if(first.length() != second.length()) return false;

        for(char c : first.toCharArray()) {
            abc[c-'a']++;
        }
        for(char c : second.toCharArray()) {
            if(abc[c-'a']-->0) cnt--;
        }

        return cnt == 0;

        /* -------------------- END OF INSERTION --------------------*/
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numTests = sc.nextInt();

        for (int i = 0; i < numTests; i++) {
            String first = sc.next().toLowerCase();
            String second = sc.next().toLowerCase();

            System.out.println(first + " & " + second + " are " + (solveAnagrams(first, second) ? "anagrams." : "NOT anagrams."));
        }
    }
}
