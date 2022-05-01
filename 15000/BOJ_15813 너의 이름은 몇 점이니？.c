// https://www.acmicpc.net/problem/15813
#include <stdio.h>

int n, sum;
int main()
{
    scanf("%d\n", &n);
    while(n--) {
        int k;
        scanf("%c", &k);
        sum += k-'A'+1;
    }
    printf("%d", sum);
}