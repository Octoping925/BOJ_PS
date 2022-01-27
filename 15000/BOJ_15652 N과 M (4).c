// https://www.acmicpc.net/problem/15652
#include <stdio.h>

int n, m;
int arr[10];

int max(int a, int b) { return a > b ? a: b; }

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
        for(int i = max(1, now); i <= n; ++i)
            f(i, depth + 1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    f(0, 0);
}