// https://www.acmicpc.net/problem/11053
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[1001];
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    int dp[1001];
    for(int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        for(int j = 0; j < i; ++j)
        {
            if(arr[j] < arr[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }

    int max = 0;
    for(int i = 0; i < n; ++i)
        if(dp[i] > max) max = dp[i];
    printf("%d", max);
}