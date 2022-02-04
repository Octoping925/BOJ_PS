// https://www.acmicpc.net/problem/11727
#include <stdio.h>

int main()
{
    int n;
    int ans[1010] = { 1, 1, 3, };
    
    scanf("%d", &n);
    
    for(int i = 3; i <= n; ++i)
        ans[i] = (ans[i - 1] + ans[i - 2] + ans[i - 2]) % 10007;
        
    printf("%d", ans[n]);
    return 0;
}