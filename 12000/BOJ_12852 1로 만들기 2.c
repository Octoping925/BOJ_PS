// https://www.acmicpc.net/problem/12852
#include <stdio.h>

int dp[1000010];
int prev[1000010];
int n;

void check(int now, int prv) {
    if(prv <= n && dp[now] > dp[prv] + 1) {
        dp[now] = dp[prv] + 1;
        prev[now] = prv;
    }
}

int main()
{
    scanf("%d", &n);

    for(int i = 1; i < n; ++i) {
        dp[i] = 9999999;
    }

    for(int i = n-1; i >= 1; i--) {
        check(i, 3*i);
        check(i, 2*i);
        check(i, i+1);
    }

    printf("%d\n", dp[1]);

    dp[0] = 1;
    int size = 1;
    while(dp[size-1] < n) {
        dp[size++] = prev[dp[size-1]];
    }

    for(int i = size-1; i >= 0; --i) {
        printf("%d ", dp[i]);
    }

    return 0;
}