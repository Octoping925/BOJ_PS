// https://www.acmicpc.net/problem/18414
#include <stdio.h>

int x, l, r;

int main()
{
    int answer;
    scanf("%d %d %d", &x, &l, &r);
    if(l <= x && x <= r) answer = x;
    else if(x < l) answer = l;
    else answer = r;
    printf("%d", answer);
}