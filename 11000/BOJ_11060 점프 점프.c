// https://www.acmicpc.net/problem/11060
#include <stdio.h>

int n;
int map[1010];
int dp[1010];

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &map[i]);
    }

    dp[1] = 0;
    for(int i = 2; i <= n; ++i) {
        dp[i] = 2100000000;
    }

    for(int i = 1; i <= n; ++i) {

        for(int j = 1; j <= map[i]; ++j) {
            if(i + j > n) break;

            if(dp[i + j] > dp[i] + 1) {
                dp[i+j] = dp[i] + 1;
            }
        }
    }
    
    if(dp[n] == 2100000000) printf("-1");
    else printf("%d", dp[n]);

    return 0;
}