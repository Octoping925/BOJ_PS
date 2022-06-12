// https://www.acmicpc.net/problem/2150
#include <stdio.h>

int map[10001][10001];
int visited[10001];
int stack[10001], stackSize;

int dfs(int x) {
    for(int i = 1; i <= map[x][0]; ++i) {
        if(!visited[map[x][i]])
            dfs(map[x][i]);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        map[x][++map[x][0]] = y;
    }



}