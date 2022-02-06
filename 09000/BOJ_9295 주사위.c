// https://www.acmicpc.net/problem/9295
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int x, y;
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d %d", &x, &y);
        printf("Case %d: %d\n", i, x+y);
    }
}