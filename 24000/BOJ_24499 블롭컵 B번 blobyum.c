// https://www.acmicpc.net/problem/24499
// 블롭컵 B번
#include <stdio.h>
int dp[100010], arr[100010];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    
    for(int i = 0; i < k; ++i)
        dp[k - 1] += arr[i];
    
    
    int sum = dp[k - 1];
    for(int i = k; i < n; ++i)
    {
        sum = sum - arr[i - k] + arr[i];
        dp[i] = sum;
    }
    
    sum = dp[n - 1];
    for(int i = 0; i < k - 1; ++i)
    {
        sum = sum - arr[n - k + i] + arr[i];
        dp[i] = sum;
    }
    
    int max = 0;
    for(int i = 0; i < n; ++i)
        if(dp[i] > max)
            max = dp[i];
            
    printf("%d", max);
}