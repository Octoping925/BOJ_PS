//https://www.acmicpc.net/problem/2178
#include <stdio.h>

char maze[101][101];
int visited[101][101];
int min, n, m;

void dfs(int x, int y, int len)
{
    if(x == n && y == m) {
        if(len < min) min = len;
        return;
    }
    if(len > min) return;
    visited[x][y] = len;

    if(len+1 < visited[x-1][y] && maze[x-1][y] == '1') {
        dfs(x-1, y, len+1);
    }
    if(len+1 < visited[x][y-1] && maze[x][y-1] == '1') {
        dfs(x, y-1, len+1);
    }
    if(len+1 < visited[x+1][y] && maze[x+1][y] == '1') {
        dfs(x+1, y, len+1);
    }
    if(len+1 < visited[x][y+1] && maze[x][y+1] == '1') {
        dfs(x, y+1, len+1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    min = n * m;
    
    for(int i = 1; i <= n; ++i) {
        scanf("%s", &maze[i][1]);
        for(int j = 1; j <= m; ++j)
            visited[i][j] = min;
    }

    dfs(1,1,1);
    printf("%d", min);
    return 0;
}

