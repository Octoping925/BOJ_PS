// https://www.acmicpc.net/problem/1106
#include <stdio.h>

int c, n;
int ad[21][2];
int dp[1200];

int min(int x, int y) {
    return x < y ? x : y;
}

int main()
{

    int max = 0;
    scanf("%d %d", &c, &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &ad[i][0], &ad[i][1]);
        if(max < ad[i][1]) max = ad[i][1];
    }

    for(int i = 1; i <= c+max; ++i) {
        dp[i] = 10000000;
    }

    for(int i = 1; i <= c; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i - ad[j][1] >= 0) {
                dp[i] = min(dp[i], dp[i - ad[j][1]] + ad[j][0]);
            }
        }
    }

    for(int i = c+1; i <= c+max; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i - ad[j][1] >= 0) {
                dp[c] = min(dp[c], dp[i - ad[j][1]] + ad[j][0]);
            }
        }
    }
    
    printf("%d", dp[c]);
}