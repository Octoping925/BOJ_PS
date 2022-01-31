// https://www.acmicpc.net/problem/2630
#include <stdio.h>

int white, blue, n;
int paper[129][129];


int isSame(int x, int y, int l)
{
    int k = paper[x][y];

    for(int i = x; i < x + l; ++i)
        for(int j = y; j < y + l; ++j)
            if(paper[i][j] != k)
                return 0;

    return 1;
}

void cut(int x, int y, int l)
{
    if(isSame(x, y, l)) {
        if(paper[x][y] == 1) ++blue;
        else ++white;
        return;
    }

    int halfL = l / 2;

    cut(x, y, halfL);
    cut(x, y + halfL, halfL);
    cut(x + halfL, y, halfL);
    cut(x + halfL, y + halfL, halfL);
}

int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            scanf("%d", &paper[i][j]);

    cut(1, 1, n);
    printf("%d\n%d", white, blue);

    return 0;
}