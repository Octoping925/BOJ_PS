// https://www.acmicpc.net/problem/12869
#include <stdio.h>

int dp[71][71][71];
int scv[3];

void init() {
    for(int i = 0; i <= 70; ++i) {
        for(int j = 0; j <= 70; ++j) {
            for(int k = 0; k <= 70; ++k) {
                dp[i][j][k] = 999;
            }
        }
    }

    dp[scv[0]][scv[1]][scv[2]] = 0;
}

int beforeAttack(int x, int dmg, int maxHealth) {
    return x+dmg < maxHealth ? x+dmg : maxHealth;
}

int min(int x, int y, int z) {
    int arr[6] = {
        dp[beforeAttack(x, 1, scv[0])][beforeAttack(y, 3, scv[1])][beforeAttack(z, 9, scv[2])],
        dp[beforeAttack(x, 1, scv[0])][beforeAttack(y, 9, scv[1])][beforeAttack(z, 3, scv[2])],
        dp[beforeAttack(x, 3, scv[0])][beforeAttack(y, 1, scv[1])][beforeAttack(z, 9, scv[2])],
        dp[beforeAttack(x, 3, scv[0])][beforeAttack(y, 9, scv[1])][beforeAttack(z, 1, scv[2])],
        dp[beforeAttack(x, 9, scv[0])][beforeAttack(y, 1, scv[1])][beforeAttack(z, 3, scv[2])],
        dp[beforeAttack(x, 9, scv[0])][beforeAttack(y, 3, scv[1])][beforeAttack(z, 1, scv[2])],
    };

    int min = arr[0] + 1;
    for(int i = 1; i < 6; ++i) {
        if(arr[i] + 1 < min) {
            min = arr[i] + 1;
        }
    }

    if(dp[x][y][z] < min) {
        min = dp[x][y][z];
    }

    return min;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &scv[i]);
    }

    init();

    for(int i = scv[0]; i >= 0; i--) {
        for(int j = scv[1]; j >= 0; j--) {
            for(int k = scv[2]; k >= 0; k--) {
                dp[i][j][k] = min(i, j, k);
            }
        }
    }

    printf("%d", dp[0][0][0]);

    return 0;
}