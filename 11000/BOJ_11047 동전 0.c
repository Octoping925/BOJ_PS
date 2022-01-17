//https://www.acmicpc.net/problem/11047
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int* price = malloc(sizeof(int) * (n + 1));
    for(int i = 0; i < n; ++i)
        scanf("%d", &price[i]);

    int cnt = 0;
    for(int i = n - 1; i >= 0; --i)
    {
        if(k == 0) break;
        
        int tmp = k / price[i];
        cnt += tmp;
        k -= tmp * price[i];
    }
    
    printf("%d", cnt);
    return 0;
}