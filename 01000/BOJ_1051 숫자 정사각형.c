// https://www.acmicpc.net/problem/1051
#include <stdio.h>

char map[51][51];

int min(int x, int y) {
    return x < y ? x : y;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; ++i) {
        scanf("%s", map+i);
    }

    int len = 2;
    int answer = 1;

    int sw = 0;
    while(len <= min(n, m)) {
        for(int i = 0; i < n; ++i) {
            if(len + i > n) break;
            for(int j = 0; j < m; ++j) {
                if(len+j > m) break;

                if(map[i][j] == map[i][j+len-1]
                 && map[i][j+len-1] == map[i+len-1][j]
                 && map[i+len-1][j+len-1] == map[i][j+len-1]) {
                    sw = 1;
                }
            }
        }

        if(sw) {
            answer = len;
            sw = 0;
        }
        ++len;
    }

    printf("%d", answer * answer);
    return 0;
}