// https://www.acmicpc.net/problem/5533
#include <stdio.h>

int num[201][3];
int score[201];
int chk[101];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &num[i][0], &num[i][1], &num[i][2]);
    }

    for(int i = 0; i < 3; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(!chk[num[j][i]]) {
                chk[num[j][i]] = j;
            }
            else {
                chk[num[j][i]] = -1;
            }
        }

        for(int j = 1; j <= 100; ++j) {
            if(chk[j] > 0) {
                score[chk[j]] += j;
            }
            chk[j] = 0;
        }
    }

    for(int i = 1; i <= n; ++i) {
        printf("%d\n", score[i]);
    }

    return 0;
}