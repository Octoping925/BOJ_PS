// https://www.acmicpc.net/problem/1520
#include <stdio.h>

int arr[502][502];
int dp[502][502];

int dfs(int x, int y) {
    if(dp[x][y] != -1) return dp[x][y];

    int sum = 0;
    int cur = arr[x][y];
    if(cur < arr[x-1][y]) sum += dfs(x-1, y);
    if(cur < arr[x][y-1]) sum += dfs(x, y-1);
    if(cur < arr[x+1][y]) sum += dfs(x+1, y);
    if(cur < arr[x][y+1]) sum += dfs(x, y+1);
    return dp[x][y] = sum;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &arr[i][j]);
            dp[i][j] = -1;
        }
    }

    dp[1][1] = 1;
    printf("%d", dfs(n, m));
}