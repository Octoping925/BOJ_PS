// https://www.acmicpc.net/problem/18005
#include <stdio.h>

int upper(double x) {
    if((int) x != x) return ((int) x) + 1;
    return (int) x;
}

int down(double x) {
    return (int) x;
}

int main() {
    int n;
    scanf("%d", &n);

    int u = upper(n/2.0);
    int d = down(n/2.0);

    if(u % 2 + d % 2 == 0) printf("2");
    else if(u % 2 * d % 2 == 0) printf("0");
    else printf("1");
}