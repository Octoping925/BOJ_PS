// https://www.acmicpc.net/problem/5604
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        back(n, n, new ArrayList<>());
    }

    static void back(int n, int recent, ArrayList<Integer> arr) {
        if(n == 0) {
            for(int i : arr) {
                System.out.printf("%d ", i);
            }
            System.out.println();
            return;
        }

        for(int i = Math.min(recent, n); i >= 1; --i) {
            arr.add(i);
            back(n-i, i, arr);
            arr.remove(arr.size()-1);
        }
    }
}