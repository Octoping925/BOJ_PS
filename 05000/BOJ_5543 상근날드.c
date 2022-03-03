// https://www.acmicpc.net/problem/5543
#include <stdio.h>

int main()
{
    int a[10];
    scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);

    int min1 = a[0], min2 = a[3];

    for (int i = 1; i <= 2; ++i) if (min1 > a[i]) min1 = a[i];
    if (min2 > a[4]) min2 = a[4];

    printf("%d", min1 + min2 - 50);
    return 0;
}