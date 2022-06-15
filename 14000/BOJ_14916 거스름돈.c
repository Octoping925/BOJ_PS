// https://www.acmicpc.net/problem/14916
#include <stdio.h>

int dp[100010] = {0, 99999, 1, 99999, 2};
int n;

int min(int x, int y) {
    return x < y ? x : y;
}

int main()
{
    scanf("%d", &n);
    for(int i = 5; i <= n; ++i) {
        dp[i] = min(dp[i - 2], dp[i - 5]) + 1;
    }

    printf("%d", dp[n] < 99999 ? dp[n] : -1);
    return 0;
}