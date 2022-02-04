// https://www.acmicpc.net/problem/1018
#include <stdio.h>

char arr[55][55];

int check(int x, int y)
{
    int cntB = 0, cntW = 0, sw = 1, tmp;
    for(int i = x; i <= x + 7; ++i)
    {
        tmp = sw * -1;
        for(int j = y; j <= y + 7; ++j)
        {
            if(arr[i][j] == 'B' && sw == 1) ++cntB;
            if(arr[i][j] == 'W' && sw == -1) ++cntB;
            if(arr[i][j] == 'B' && sw == -1) ++cntW;
            if(arr[i][j] == 'W' && sw == 1) ++cntW;
            sw *= -1;
        }
        sw = tmp;
    }
    return cntB < cntW ? cntB : cntW;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
        scanf("%s", arr+i);

    int min = 2100000000;
    for(int i = 0; i <= n - 8; ++i)
    {
        for(int j = 0; j <= m - 8; ++j)
        {
            int chk = check(i, j);
            if(min > chk) min = chk;
        }
    }

    printf("%d", min);
    return 0;
}
