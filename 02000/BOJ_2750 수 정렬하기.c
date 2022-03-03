// https://www.acmicpc.net/problem/2750
#include <stdio.h>

int n, k, t, a[1010];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
    {
        k = i;
        for (int j = i; j <= n; ++j) if (a[k] > a[j]) k = j;
        t = a[i], a[i] = a[k], a[k] = t;
    }
    
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
    return 0;
}