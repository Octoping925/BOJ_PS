// https://www.acmicpc.net/problem/15649
#include <stdio.h>

int n, m;
int arr[10];
int chk[10];

int f(int now, int depth)
{
    arr[depth] = now;
    
    if(depth == m)
    {
        for(int i = 1; i <= depth; ++i)
            printf("%d ", arr[i]);
        printf("\n");
        arr[depth] = 0;
    }
    else
    {
        for(int i = 1; i <= n; ++i)
            if(!chk[i]) {
                chk[i]++;
                f(i, depth + 1);
                chk[i]--;
            }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    f(0, 0);
}