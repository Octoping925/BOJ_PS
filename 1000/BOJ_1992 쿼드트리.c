// https://www.acmicpc.net/problem/1992
#include <stdio.h>

char arr[129][129];

int isSame(int x, int y, int l)
{
    char k = arr[x][y];

    for(int i = x; i < x + l; ++i)
        for(int j = y; j < y + l; ++j)
            if(arr[i][j] != k)
                return 0;

    return 1;
}

void cut(int x, int y, int l)
{
    if(isSame(x, y, l)) {
        printf("%c", arr[x][y]);
        return;
    }

    int halfL = l / 2;

    printf("(");
    cut(x, y, halfL);
    cut(x, y + halfL, halfL);
    cut(x + halfL, y, halfL);
    cut(x + halfL, y + halfL, halfL);
    printf(")");
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i)
        scanf("%s", arr + i);

    cut(0, 0, n);

    return 0;
}