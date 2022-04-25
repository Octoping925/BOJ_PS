// https://www.acmicpc.net/problem/14226
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

class Move
{
    int cnt;
    int clip;
    int second;

    Move(int cnt, int clip, int second) {
        this.cnt = cnt;
        this.clip = clip;
        this.second = second;
    }
}

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[][] dp = new int[n*2][n];
        for(int i = 0; i < n*2; ++i) {
            for(int j = 0; j < n; ++j) {
                dp[i][j] = n;
            }
        }

        Queue<Move> q = new LinkedList<>();
        q.add(new Move(1, 0, 0));

        while(!q.isEmpty()) {
            Move p = q.poll();
            if(p.second >= dp[p.cnt][p.clip]) continue;
            dp[p.cnt][p.clip] = p.second;
            if(p.cnt == n) continue;

            if(p.clip != p.cnt && Math.abs(n-(p.cnt+p.clip)) > Math.abs(n-(p.cnt*2))) q.add(new Move(p.cnt, p.cnt, p.second+1));
            if(p.cnt < n && p.clip > 0) q.add(new Move(p.cnt + p.clip, p.clip, p.second+1));
            if(p.cnt > 2) q.add(new Move(p.cnt-1, p.clip, p.second+1));
        }

        int min = n;
        for(int i : dp[n]) {
            if(i < min) min = i;
        }

        System.out.println(min);
    }
}
