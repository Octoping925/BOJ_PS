// https://www.acmicpc.net/problem/15917
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n; ++i)
    {
        int q;
        scanf("%d", &q);
        printf("%d\n", (q&(-q))==q ? 1 : 0);
    }
}