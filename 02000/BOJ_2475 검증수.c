// https://www.acmicpc.net/problem/2475
#include <stdio.h>
int main()
{
    int a, b = 0;
    for(int i = 0; i < 5; ++i) {
        scanf("%d", &a);
        b += (a * a) % 10;
    }
    printf("%d", b % 10);
}