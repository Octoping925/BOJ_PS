// https://www.acmicpc.net/problem/2525
#include <stdio.h>

int main()
{
    int h, m;
    scanf("%d %d", &h, &m);
    int p;
    scanf("%d", &p);
    m += p;
    h += m/60;
    m %= 60;
    h %= 24;
    printf("%d %d", h, m);
}