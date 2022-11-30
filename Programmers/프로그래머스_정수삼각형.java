import java.util.Arrays;

class Solution {
    public int solution(int[][] triangle) {
        int len = triangle.length;
        int[][] dp = new int[len][len];

        dp[0][0] = triangle[0][0];

        for(int i = 1; i < len; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(j == i) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                }
                else if(j == 0) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                }
                else {
                    dp[i][j] = triangle[i][j] + Math.max(dp[i-1][j-1], dp[i-1][j]);
                }
            }
        }

        return Arrays.stream(dp[len - 1]).max().getAsInt();
    }
}