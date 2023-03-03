// https://www.acmicpc.net/problem/16173
#include <stdio.h>

int map[3][3];
int n;

int DFS(int x, int y) {
    if(x == n-1 && y == n-1) {
        return 1;
    }
    
    int dist = map[x][y];
    
    if(dist == 0) {
        return 0;
    }
    
    int newX = x + dist;
    int newY = y + dist;
    
    if(newX < n) {
        int isArrived = DFS(newX, y);
        if(isArrived) {
            return 1;
        }
    }
    
    if(newY < n) {
        int isArrived = DFS(x, newY);
        if(isArrived) {
            return 1;
        }
    }
    
    return 0;
}

int main()
{
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    
    printf("%s", DFS(0, 0) ? "HaruHaru" : "Hing");
    return 0;
}