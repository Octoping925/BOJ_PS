// https://www.acmicpc.net/problem/1932
#include <stdio.h>

int arr[510][510], chk[510][510];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= i; ++j)
            scanf("%d", &arr[i][j]);
    
    chk[1][1] = arr[1][1];

    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            if(j == 1) chk[i][j] = chk[i - 1][j] + arr[i][j];
            else if(j == i) chk[i][j] = chk[i - 1][j - 1] + arr[i][j];
            else {
                int max = chk[i - 1][j - 1] > chk[i - 1][j] ? chk[i - 1][j - 1] : chk[i - 1][j];
                chk[i][j] = arr[i][j] + max;
            }
        }
    }

    int max = chk[n][1];
    for(int i = 2; i <= n; ++i)
        if(max < chk[n][i])
            max = chk[n][i];

    printf("%d", max);
    return 0;
}