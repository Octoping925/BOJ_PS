// https://www.acmicpc.net/problem/1834
#include <stdio.h>

int n;

int main()
{
    scanf("%d", &n);
    printf("%lld", (long long) (n+1) * n * (n-1) / 2);
}

/*
X / N = K . . . K

k*n + k  =  k*(n+1) = X

0 <= k < n

(n+1) * (n * (n-1) / 2)
*/