// https://www.acmicpc.net/problem/10768
#include <stdio.h>
int main(m,d) {
    scanf("%d %d", &m, &d);
    int md = m*100+d;
    printf(md == 218 ? "Special" : md > 218 ? "After" : "Before");
}