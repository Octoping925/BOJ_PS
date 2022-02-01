// https://www.acmicpc.net/problem/2447
#include <stdio.h>

int n;
int arr[6570][6570];

int power(int x, int y)
{
    int sum = 1;
    for(int i = 0; i < y; ++i) sum *= x;
    return sum;
}

void recursive(int depth, int x, int y)
{
    if(depth == 1)
    {
        arr[x][y] = arr[x+1][y] = arr[x+2][y] = 1;
        arr[x][y+1] = arr[x+2][y+1] = 1;
        arr[x][y+2] = arr[x+1][y+2] = arr[x+2][y+2] = 1;
        arr[x+1][y+1] = 0;
        return;
    }

    int len = power(3, depth - 1);

    recursive(depth - 1, x + len * 0, y + len * 0);
    recursive(depth - 1, x + len * 1, y + len * 0);
    recursive(depth - 1, x + len * 2, y + len * 0);
    
    recursive(depth - 1, x + len * 0, y + len * 1);
    //recursive(depth - 1, x + len * 1, y + len * 1);
    recursive(depth - 1, x + len * 2, y + len * 1);
    
    recursive(depth - 1, x + len * 0, y + len * 2);
    recursive(depth - 1, x + len * 1, y + len * 2);
    recursive(depth - 1, x + len * 2, y + len * 2);
}

int main()
{
    scanf("%d", &n);
    int k = n, cnt = 0;
    while(k > 1) {
        k /= 3;
        cnt++;
    }
    recursive(cnt, 1, 1);

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            printf("%c", arr[i][j] == 1 ? '*' : ' ');
        printf("\n");
    }
}