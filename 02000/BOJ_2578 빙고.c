// https://www.acmicpc.net/problem/2578
#include <stdio.h>
#define LEN 5

typedef struct point {
    int x;
    int y;
} Point;

int charles[LEN][LEN];
int chk[LEN][LEN];

int isGaroBingo(int y) {
    return chk[0][y] &&
           chk[1][y] &&
           chk[2][y] &&
           chk[3][y] &&
           chk[4][y];
}

int isSeroBingo(int x) {
    return chk[x][0] &&
           chk[x][1] &&
           chk[x][2] &&
           chk[x][3] &&
           chk[x][4];
}

int isDiagonalBingo() {
    return (chk[0][0] && chk[1][1] && chk[2][2] && chk[3][3] && chk[4][4])
           + (chk[4][0] && chk[3][1] && chk[2][2] && chk[1][3] && chk[0][4]);
}

int countBingo() {
    int cnt = 0;
    for (int i = 0; i < 5; ++i) {
        cnt += isGaroBingo(i) + isSeroBingo(i);
    }
    cnt += isDiagonalBingo();

    return cnt;
}

Point findPosition(int num) {
    for (int i = 0; i < LEN; ++i) {
        for (int j = 0; j < LEN; ++j) {
            if (charles[i][j] == num) {
                return (Point) {i, j};
            }
        }
    }
}

int main() {
    for (int i = 0; i < LEN; ++i) {
        for (int j = 0; j < LEN; ++j) {
            scanf("%d", &charles[i][j]);
        }
    }

    for (int i = 1; i <= 25; ++i) {
        int k;
        scanf("%d", &k);

        Point p = findPosition(k);
        chk[p.x][p.y] = 1;

        if (countBingo() >= 3) {
            printf("%d", i);
            break;
        }
    }

    return 0;
}
