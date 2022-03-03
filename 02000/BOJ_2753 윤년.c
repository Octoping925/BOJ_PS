// https://www.acmicpc.net/problem/2753
#include <stdio.h>

int n;

int main()
{
    scanf("%d", &n);
    if (n % 400 == 0) printf("1");
    else if (n % 4 == 0 && n % 100 != 0) printf("1");
    else printf("0");
    return 0;
}