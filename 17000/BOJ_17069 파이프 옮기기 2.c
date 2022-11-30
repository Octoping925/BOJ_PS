// https://www.acmicpc.net/problem/17069
#include <stdio.h>

int home[33][33];

long long pipe_garo[33][33];
long long pipe_sero[33][33];
long long pipe_degak[33][33];

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%d", &home[i][j]);
        }
    }

    pipe_garo[1][2] = 1;

    for(int i = 1; i <= n; ++i) {
        for(int j = 2; j <= n; ++j) {
            if(home[i][j] == 1) continue;

            pipe_garo[i][j] += pipe_garo[i][j-1] + pipe_degak[i][j-1];
            pipe_sero[i][j] += pipe_sero[i-1][j] + pipe_degak[i-1][j];

            if(home[i-1][j] + home[i][j-1] == 0) {
                pipe_degak[i][j] += pipe_garo[i-1][j-1] + pipe_sero[i-1][j-1] + pipe_degak[i-1][j-1];
            }
        }
    }

    printf("%lld", pipe_garo[n][n] + pipe_sero[n][n] + pipe_degak[n][n]);
    return 0;
}