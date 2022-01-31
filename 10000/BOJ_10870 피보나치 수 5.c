// https://www.acmicpc.net/problem/10870
#include <stdio.h>

int main()
{
    int n;
    int ans[22] = { 0, 1, 1, 2, };
    
    scanf("%d", &n);
    
    for(int i = 4; i <= n; ++i)
        ans[i] = ans[i - 1] + ans[i - 2];
        
    printf("%d", ans[n]);
    return 0;
}
