#include <stdio.h>

int n, m, ans;
int chk[1010][1010][2];
int map[1010][1010];

int min(int x, int y) { return x < y ? x : y; }

int play(int x, int y, int depth, int status)
{
    if(x == 1 && y == 1) return chk[x][y][status] = 1;
    if(depth >= chk[x][y][status]) return 9999999;

    if(status == 0) {
        if(x > 0) play(x-1, y, depth+1, status);
    }
    
    return;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", map[i] + 1);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            chk[i][j][0] = chk[i][j][1] = n * m + 1;

    chk[1][1][0] = chk[1][1][1] = 1;

    play(n, m, 0);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) printf("%d ", chk[i][j][0]);
        printf("\n");
    }
    printf("\n\n");
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) printf("%d ", chk[i][j][1]);
        printf("\n");
    }

    ans = min(chk[n][m][0], chk[n][m][1]);
    if (ans == n * m + 1) printf("-1");
    else printf("%d", ans);

    return 0;
}