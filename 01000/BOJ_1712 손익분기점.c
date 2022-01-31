// https://www.acmicpc.net/problem/1712
#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(b == c || ((int) a / (c - b)) + 1 <= 0) printf("-1");
    else printf("%d", ((int) a / (c - b)) + 1);
    return 0;
}