// https://www.acmicpc.net/problem/2667
#include <stdio.h>

char arr[26][26];
int queue[626][2];
int danji[626];
int cnt, start, end;

void putQueue(int x, int y)
{
    queue[end][0] = x;
    queue[end][1] = y;
    ++end;
    arr[x][y] = '0';
}

int bfs(int x, int y)
{
    start = 0, end = 1;
    putQueue(x, y);
    
    int size = 0;
    while(start < end)
    {
        x = queue[start][0], y = queue[start][1];
        ++start;
        ++size;

        if(x > 0 && arr[x-1][y] == '1') {
            putQueue(x-1, y);
        }
        if(arr[x+1][y] == '1') {
            putQueue(x+1, y);
        }
        if(y > 0 && arr[x][y-1] == '1') {
            putQueue(x, y-1);
        }
        if(arr[x][y+1] == '1') {
            putQueue(x, y+1);
        }
    }
    return size - 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i)
        scanf("%s", arr+i);
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(arr[i][j] == '1') {
                danji[cnt++] = bfs(i, j);
            }
        }
    }


    for(int i = 0; i < cnt; ++i) {
        for(int j = 1; j < cnt; ++j) {
            if(danji[j-1] > danji[j]) {
                int tmp = danji[j];
                danji[j] = danji[j-1];
                danji[j-1] = tmp;
            }
        }
    }
            
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; ++i)
        printf("%d\n", danji[i]);
}