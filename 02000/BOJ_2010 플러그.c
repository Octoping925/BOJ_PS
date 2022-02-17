// https://www.acmicpc.net/problem/2010
#include <stdio.h>
int n, k, sum = 1;
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &k);
        sum += k - 1;
    }
    printf("%d", sum);
}