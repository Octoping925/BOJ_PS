// https://www.acmicpc.net/problem/11057
#include <stdio.h>

int n, arr[1001][10];

int main() {
    scanf("%d", &n);

    for(int i = 0; i <= 9; ++i) {
        arr[0][i] = 1;
    }

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j <= 9; ++j) {
            for(int k = j; k <= 9; ++k) {
                arr[i][j] += arr[i-1][k];
                arr[i][j] %= 10007;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i <= 9; ++i) {
        sum += arr[n-1][i];
        sum %= 10007;
    }

    printf("%d", sum);
}