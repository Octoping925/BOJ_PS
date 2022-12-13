// https://www.acmicpc.net/problem/20162
#include <stdio.h>
#define SCORE_LIMIT 100000

int arr[1001];
int dp[1001][SCORE_LIMIT + 1];

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i <= n; ++i) {
        int prevMax = 0;
        for(int j = 0; j <= SCORE_LIMIT; ++j) {
            if(j == arr[i]) {
                dp[i][j] = prevMax + arr[i];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
            prevMax = max(dp[i-1][j], prevMax);
        }
    }

    int maxScore = 0;
    for(int i = 1; i <= SCORE_LIMIT; ++i) {
        if(dp[n][i] > maxScore) {
            maxScore = dp[n][i];
        }
    }

    printf("%d", maxScore);
    return 0;
}