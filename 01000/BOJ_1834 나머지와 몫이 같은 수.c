// https://www.acmicpc.net/problem/1834
#include <stdio.h>

int n;

int main()
{
    scanf("%d", &n);
    printf("%lld", (long long) (n+1) * n * (n-1) / 2);
}