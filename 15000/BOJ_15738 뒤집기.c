// https://www.acmicpc.net/problem/15738
#include <stdio.h>

int main()
{
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);

    for(int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
    }

    n = 2*n-1;
    k = 2*k-1;

    while(m--) {
        int p;
        scanf("%d", &p);

        if(p > 0) p = 2*p-1;
        else p = 2*p+1;

        if(p > 0 && k <= p) {
            k = k - (k - (p+1)/2) * 2;
        }
        else if(p < 0 && k > n+p) {
            k = k - (k - ((n+p+1 + n) / 2)) * 2;
        }

    }

    printf("%d", (k+1)/2);
}