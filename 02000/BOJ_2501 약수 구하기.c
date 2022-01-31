// https://www.acmicpc.net/problem/2501
#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(n % i == 0)
        {
            ++cnt;
            if(cnt == m) {
                printf("%d", i);
                return 0;
            }
        }
    }
    
    printf("0");
    return 0;
}