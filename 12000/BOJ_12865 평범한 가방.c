// https://www.acmicpc.net/problem/12865
#include <stdio.h>

int info[110][3];
int dp[110][100010];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; ++i)
        scanf("%d %d", &info[i][1], &info[i][2]); // 무게, 가치
    
    //dp[i][j] = 현재무게 i에서 j개의 물건을 담았을 때 최대가치

    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= n; ++j)
        {
            if(info[i][1] > i) {
                
            }
            else {

            }
        }
    }
    
}