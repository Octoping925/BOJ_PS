// https://www.acmicpc.net/problem/32289

#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%lld", (long long) 4 * a * b - 3 * a - 3 * b + 2);
}

/*
(a-1) * b 가로
(b-1) * a 세로
(a-1) * (b-1) * 2 대각선


4ab-3a-3b+2
*/