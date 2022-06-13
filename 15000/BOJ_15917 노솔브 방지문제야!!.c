// https://www.acmicpc.net/problem/15917
#include <stdio.h>
int n, q;
int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &q);
        printf("%d\n", (q&(-q))==q);
    }
}