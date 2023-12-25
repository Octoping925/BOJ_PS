// https://www.acmicpc.net/problem/14470
#include <stdio.h>

int main() {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    if(a < 0) printf("%d", (-a) * c + d + e * b);
    else printf("%d", (b - a) * e);
}