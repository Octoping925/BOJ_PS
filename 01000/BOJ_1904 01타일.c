// https://www.acmicpc.net/problem/1904
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int* ans = malloc(sizeof(int) * (n + 5));
    
    ans[1] = 1;
    ans[2] = 2;
    
    for(int i = 3; i <= n; ++i)
    {
        ans[i] = ans[i - 1] % 15746 + ans[i - 2] % 15746;
    }
    
    printf("%d", ans[n] % 15746);
    
    return 0;
}