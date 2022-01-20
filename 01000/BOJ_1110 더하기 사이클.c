// https://www.acmicpc.net/problem/1110
#include <stdio.h>

int parse(int n, int x, int cnt)
{ 
    return cnt > 0 && x == n ? cnt : parse(n, x % 10 * 10 + (x / 10 + x % 10) % 10, cnt + 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", parse(n, n, 0));
}