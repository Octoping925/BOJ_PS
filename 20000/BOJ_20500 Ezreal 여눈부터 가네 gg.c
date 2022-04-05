// https://www.acmicpc.net/problem/20500
#include <stdio.h>

int n;
int comb[1516][3];

int main()
{
    scanf("%d", &n);

    comb[1][2] = 1;

    for(int i = 2; i <= n; ++i) {
        comb[i][0] = (comb[i-1][2] + comb[i-1][1]) % 1000000007;
        comb[i][1] = (comb[i-1][0] + comb[i-1][2]) % 1000000007;
        comb[i][2] = (comb[i-1][1] + comb[i-1][0]) % 1000000007;
    }

    printf("%d", comb[n][0]);
}