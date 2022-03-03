https://www.acmicpc.net/problem/1330
#include <stdio.h>

int main()
{
    int a[10];
    scanf("%d %d", &a[0], &a[1]);

    if (a[0] < a[1]) printf("<");
    if (a[0] > a[1]) printf(">");
    if (a[0] == a[1]) printf("==");
    return 0;
}