// https://www.acmicpc.net/problem/2240
#include <stdio.h>

int max(int x, int y) {
    return x > y ? x : y;
}
int min(int x, int y) {
    return x < y ? x : y;
}

int dp[1010][3][31];

int main()
{
    int t, w;
    scanf("%d %d", &t, &w);

    for(int i = 1; i <= t; ++i) {
        int pos;
        scanf("%d", &pos);

        dp[1][2][0] = 0;
        dp[i][1][0] = dp[i-1][1][0];
        dp[i][pos][0]++;

        for(int k = 1; k <= min(w, i); ++k) {
            dp[i][1][k] = max(dp[i-1][1][k], dp[i-1][2][k-1]);
            dp[i][2][k] = max(dp[i-1][2][k], dp[i-1][1][k-1]);
            dp[i][pos][k]++;
        }
    }

    int answer = 0;
    for(int i = 0; i <= w; ++i) {
        if(dp[t][1][i] > answer) answer = dp[t][1][i];
        if(dp[t][2][i] > answer) answer = dp[t][2][i];
    }

    printf("%d", answer);
}