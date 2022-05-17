// https://www.acmicpc.net/problem/2559
#include <stdio.h>
int arr[100010], dp[100010];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i <= m; ++i) {
        dp[m] += arr[i];
    }

    int max = dp[m];
    for(int i = m + 1; i <= n; ++i) {
        dp[i] = dp[i-1] + arr[i] - arr[i-m];
        if(dp[i] > max) max = dp[i];
    }

    printf("%d", max);
}
