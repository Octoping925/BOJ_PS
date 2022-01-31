// https://www.acmicpc.net/problem/11659
#include <stdio.h>

int arr[100010];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    int k;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &k);
        arr[i] = arr[i - 1] + k;
    }
    
    for(int i = 0; i < m; ++i)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", arr[r] - arr[l - 1]);
    }
}