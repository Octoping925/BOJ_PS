// https://www.acmicpc.net/problem/2441
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = n; i >= 1; --i) 
    {
        for(int j = 0; j < n-i; ++j) printf(" ");
        for(int j = 0; j < i; ++j) printf("*");
        printf("\n");
    }
}