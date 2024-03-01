// https://www.acmicpc.net/problem/1953
import java.io.*;
import java.util.*;

public class Main {
    static Set<Integer>[] haters;
    static int n;

    static Set<Integer> blue = new LinkedHashSet<>();
    static Set<Integer> white = new LinkedHashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        haters = new Set[n + 1];
        for (int i = 1; i <= n; ++i)
            haters[i] = new HashSet<>();

        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int count = Integer.parseInt(st.nextToken());

            while(count-- > 0) {
                int hate = Integer.parseInt(st.nextToken());
                haters[i].add(hate);
                haters[hate].add(i);
            }
        }

        dfs(1);
    }

    static boolean dfs(int cnt) {
        if (cnt > n) {
            if(blue.isEmpty() || white.isEmpty()) {
                return false;
            }

            System.out.println(blue.size());
            for(int b : blue) {
                System.out.printf("%d ", b);
            }
            System.out.println();

            System.out.println(white.size());
            for(int w : white) {
                System.out.printf("%d ", w);
            }
            return true;
        }

        if (canAddBlue(cnt)) {
            blue.add(cnt);
            if(dfs(cnt + 1)) {
                return true;
            }
            blue.remove(cnt);
        }

        if (canAddWhite(cnt)) {
            white.add(cnt);
            if(dfs(cnt + 1)) {
                return true;
            }
            white.remove(cnt);
        }

        return false;
    }

    static boolean canAddBlue(int cnt) {
        return blue.stream()
                .noneMatch(member -> haters[member].contains(cnt));
    }

    static boolean canAddWhite(int cnt) {
        return white.stream()
                .noneMatch(member -> haters[member].contains(cnt));
    }
}