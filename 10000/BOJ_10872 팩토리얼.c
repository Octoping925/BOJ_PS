// https://www.acmicpc.net/problem/10872
#include <stdio.h>

int f(int x)
{
    if(x == 0) return 1;
    if(x == 2) return 2;
    return f(x - 1) * x;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", f(n));
}