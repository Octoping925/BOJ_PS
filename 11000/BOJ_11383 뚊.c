// https://www.acmicpc.net/problem/11383
#include <stdio.h>

char word[11][11], longWord[11][21];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; ++i) {
        scanf("%s", word+i);
    }

    for(int i = 0; i < n; ++i) {
        scanf("%s", longWord+i);
    }

    int sw = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 2 * m; ++j) {
            if(longWord[i][j] != word[i][j / 2]) {
                sw = 0;
                break;
            }
        }
    }

    printf("%s", sw ? "Eyfa\n" : "Not Eyfa\n");
    return 0;
}