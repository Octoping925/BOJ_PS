// https://www.acmicpc.net/problem/11943
#include <stdio.h>

int min(int x, int y) {
    return x < y ? x : y;
}

int main() {
    int a, b, c, d;
    scanf("%d %d\n%d %d", &a, &b, &c, &d);
    printf("%d", min(b+c, a+d));
}