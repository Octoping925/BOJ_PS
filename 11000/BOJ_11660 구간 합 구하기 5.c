// https://www.acmicpc.net/problem/11660
#include <stdio.h>

int sum[1025][1025];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int k;
            scanf("%d", &k);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + k - sum[i - 1][j - 1];
        }
    }

    for(int i = 1; i <= m; ++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1]);
    }
}