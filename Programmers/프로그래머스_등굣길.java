// https://school.programmers.co.kr/learn/courses/30/lessons/42898
class Solution {
    public int solution(int m, int n, int[][] puddles) {
        boolean[][] sink = new boolean[n+1][m+1];
        int[][] dp = new int[n+1][m+1];
        
        for(int[] point : puddles) {
            sink[point[1]][point[0]] = true;
        }
        
        dp[1][1] = 1;
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(!sink[i][j]) {
                    dp[i][j] += (dp[i-1][j] + dp[i][j-1]) % 1000000007;
                }
            }
        }
        
        return dp[n][m];
    }
}