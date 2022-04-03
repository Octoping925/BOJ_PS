// https://www.acmicpc.net/problem/1652
#include <stdio.h>
char map[101][101];
int n, garo, sero, len;

int main()
{
    scanf("%d", &n);
    scanf("%c", &map[0][0]);

    for(int i = 1; i <= n; ++i) {
        len = 0;
        for(int j = 1; j <= n; ++j) {
            scanf("%c", &map[i][j]);
            if(map[i][j] == '.') len++;
            else {
                if(len > 1) ++garo;
                len = 0;
            }
        }
        scanf("%c", &map[0][0]);
        if(len > 1) ++garo;
    }

    for(int j = 1; j <= n; ++j) {
        len = 0;
        for(int i = 1; i <= n; ++i) {
            if(map[i][j] == '.') len++;
            else {
                if(len > 1) ++sero;
                len = 0;
            }
        }
        if(len > 1) ++sero;
    }

    printf("%d %d", garo, sero);
}