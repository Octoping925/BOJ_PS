// https://www.acmicpc.net/problem/10817
#include <stdio.h>

int a, b, c;

int main()
{
	scanf("%d %d %d", &a, &b, &c);
    int ans = a;
    if((a-b)*(c-b) <= 0) ans = b;
    if((a-c)*(b-c) <= 0) ans = c;
    printf("%d", ans);
	return 0;
}