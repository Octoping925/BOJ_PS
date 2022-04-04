// https://www.acmicpc.net/problem/1712
#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    if(a>=b) printf("-1");
    else printf("%d", n/(b-a) + 1);

    return 0;
}