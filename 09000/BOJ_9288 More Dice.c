// https://www.acmicpc.net/problem/9288
#include <stdio.h>

int tc, n;
int main()
{
    scanf("%d", &tc);
    for(int i = 1; i <= tc; ++i) {
        scanf("%d", &n);
        printf("Case %d:\n", i);

        for(int j = 1; j <= 6; ++j) {
            if(0 < n-j && n-j <= 6 && j <= n-j) {
                printf("(%d,%d)\n", j, n-j);
            }
        }
    }
}