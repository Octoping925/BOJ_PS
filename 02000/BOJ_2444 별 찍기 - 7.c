// https://www.acmicpc.net/problem/2444
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n - i; ++j) printf(" ");
        for(int j = 1; j <= 2*i-1; ++j) printf("*");
        printf("\n");
    }
    for(int i = n-1; i >= 1; --i)
    {
        for(int j = 1; j <= n - i; ++j) printf(" ");
        for(int j = 1; j <= 2*i-1; ++j) printf("*");
        printf("\n");
    }
}