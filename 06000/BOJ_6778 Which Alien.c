// https://www.acmicpc.net/problem/6778
#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    if(3 <= n && m <= 4) printf("TroyMartian\n");
    if(n <= 6 && 2 <= m) printf("VladSaturnian\n");
    if(n <= 2 && m <= 3) printf("GraemeMercurian\n");
    return 0;
}