// https://www.acmicpc.net/problem/10709
#include <stdio.h>

char cloud[101][101];
int dp[101][101];

int main()
{
    int h, w;
    scanf("%d %d", &h, &w);
    for(int i = 0; i < h; ++i) {
        scanf("%s", cloud+i);
    }

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(cloud[i][j] == 'c') dp[i][j] = 0;
            else if(j == 0) dp[i][j] = -1;
            else if(dp[i][j-1] == -1) dp[i][j] = -1;
            else dp[i][j] = dp[i][j-1] + 1;
        }
    }

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    return 0;
}
