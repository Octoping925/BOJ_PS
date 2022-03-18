// https://www.acmicpc.net/problem/11048
#include <stdio.h>

int arr[1010][1010];

int max(int x, int y, int z) {
    if(x > y && x > z) return x;
    else if(y > z) return y;
    return z;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &arr[i][j]);
            arr[i][j] += max(arr[i][j - 1], arr[i - 1][j], arr[i - 1][j - 1]);
        }
    }

    printf("%d", arr[n][m]);
    return 0;
}