// https://www.acmicpc.net/problem/14562
import java.io.*;
import java.util.*;

class Score {
    int myScore;
    int enemyScore;
    int cnt;
    Score(int mine, int enemy, int cnt) {
        myScore = mine;
        enemyScore = enemy;
        this.cnt = cnt;
    }
    Score greatKick() {
        return new Score(myScore * 2, enemyScore + 3, cnt + 1);
    }
    Score smallKick() {
        return new Score(myScore + 1, enemyScore, cnt + 1);
    }
}

public class Main {

    public static void main(String[] args)  throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int c = Integer.parseInt(br.readLine());

        while(c-->0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            Queue<Score> q = new LinkedList<>();
            q.add(new Score(n, m, 0));

            int min = m;
            while(!q.isEmpty()) {
                Score p = q.poll();
                if(min < p.cnt) {
                    continue;
                }

                if(p.myScore == p.enemyScore) {
                    min = Math.min(p.cnt, min);
                    continue;
                }

                if(p.myScore * 2 <= p.enemyScore + 3) {
                    q.add(p.greatKick());
                }
                if(p.myScore < p.enemyScore) {
                    q.add(p.smallKick());
                }
            }
            System.out.println(min);
        }
    }
}