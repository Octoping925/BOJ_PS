// https://www.acmicpc.net/problem/15917
#include <stdio.h>
int n, q;
int main()
{
    scanf("%d", &n);
    for(int i = 0 ; i < n; ++i) {
        scanf("%d", &q);
        printf("%d\n", (q&(-q))==q);
    }
}