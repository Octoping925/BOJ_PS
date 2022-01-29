// https://www.acmicpc.net/problem/1912
#include <stdio.h>

int arr[100100], dp[100100];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    int max = -1000;
    for(int i = 0; i < n; ++i)
    {
        dp[i] = arr[i];
        if(i > 0 && dp[i - 1] > 0) dp[i] += dp[i - 1];
        if(dp[i] > max) max = dp[i];
    }

    printf("%d", max);
}