// https://www.acmicpc.net/problem/10768
#include <stdio.h>
int main(m,d) {
    scanf("%d %d", &m, &d);
    printf(m == 2 && d == 18 ? "Special" : (m > 2 || m == 2 && d > 18) ? "After" : "Before");
}