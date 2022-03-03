// https://www.acmicpc.net/problem/9498
#include <stdio.h>

int n;

int main()
{
    scanf("%d", &n);
    if (n >= 90) printf("A");
    else if (n >= 80) printf("B");
    else if (n >= 70) printf("C");
    else if (n >= 60) printf("D");
    else printf("F");
    return 0;
}