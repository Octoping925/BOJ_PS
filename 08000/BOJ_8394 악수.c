// https://www.acmicpc.net/problem/8394
#include <stdio.h>

int a[61];

void f(int x) {
    a[0] = 1, a[1] = 1;
    for (int i = 2; i <= x; ++i)
        a[i] = (a[i - 1] + a[i - 2]) % 10;
    printf("%d", a[x]);
}

int main()
{
    int n;
    scanf("%d", &n);
    f(n % 60);
}