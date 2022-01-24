// https://www.acmicpc.net/problem/14719
#include <stdio.h>

int arr[510][510];

int main()
{
    int sero, garo;
    scanf("%d %d", &sero, &garo);
    
    int map[510];
    for(int i = 1; i <= garo; ++i) {
        scanf("%d", &map[i]);
        for(int j = 1; j <= map[i]; ++j)
            arr[i][j] = 1;
    }


    // 탐색
    int sum = 0;

    for(int j = sero; j >= 1; --j)
    {
        int wallCnt = 0;
        int leftWallX;
        for(int i = 1; i <= garo; ++i)
        {
            if(arr[i][j])
            {
                if(wallCnt == 0) wallCnt = 1;
                else sum += i - leftWallX - 1;
                
                leftWallX = i;
            }
        }
    }

    printf("%d", sum);
    return 0;
}