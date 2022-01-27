// https://www.acmicpc.net/problem/15651
#include <stdio.h>

int n, m;
int arr[10];

void f(int now, int depth)
{
    arr[depth] = now;
    if(depth == m)
    {
        for(int i = 1; i <= depth; ++i)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else
    {
        for(int i = 1; i <= n; ++i)
            f(i, depth + 1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    f(0, 0);
}