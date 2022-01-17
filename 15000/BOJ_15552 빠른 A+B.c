// https://www.acmicpc.net/problem/15552
#include <stdio.h>
int main()
{
    int a, b, n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }
    return 0;
}