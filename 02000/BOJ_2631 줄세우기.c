// https://www.acmicpc.net/problem/2631
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[200];
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int dp[200];
    for(int i = 0; i < n; ++i) {
        dp[i] = 1;
        for(int j = 0; j < i; ++j) {
            if(arr[j] < arr[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }

    int max = 0;
    for(int i = 0; i < n; ++i)
        if(dp[i] > max) max = dp[i];
    printf("%d", n - max);
}