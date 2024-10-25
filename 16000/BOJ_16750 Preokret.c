// https://www.acmicpc.net/problem/16750
#include <stdio.h>

int main() {
    int a, b;
    int arrA[2880], arrB[2880];

    scanf("%d", &a);
    for(int i = 0; i < a; i++) {
        scanf("%d", &arrA[i]);
    }

    scanf("%d", &b);
    for(int i = 0; i < b; i++) {
        scanf("%d", &arrB[i]);
    }

    int idxA = 0, idxB = 0;
    int aScore = 0, bScore = 0;
    int turnaroundCnt = 0;
    int halfTimeCnt = 0;
    int lastLosing = 0; // -1 = a, 0 = mid, 1 = b

    while(idxA < a || idxB < b) {
        if (idxB >= b || (idxA < a && arrA[idxA] < arrB[idxB])) {
            int aSec = arrA[idxA];
            idxA++;
            aScore++;

            if (aSec <= 1440) {
                halfTimeCnt++;
            }

            if (aScore > bScore) {
                if (lastLosing == -1) {
                    turnaroundCnt++;
                }
                lastLosing = 1;
            }
        } else {
            int bSec = arrB[idxB];
            idxB++;
            bScore++;

            if (bSec <= 1440) {
                halfTimeCnt++;
            }

            if (bScore > aScore) {
                if (lastLosing == 1) {
                    turnaroundCnt++;
                }
                lastLosing = -1;
            }
        }
    }

    printf("%d\n%d", halfTimeCnt, turnaroundCnt);
}
