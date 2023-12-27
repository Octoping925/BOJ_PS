// https://www.acmicpc.net/problem/10448
#include <stdio.h>

int getTriangleNum(int k) {
    return k * (k + 1) / 2;
}

int findMaxTriangleNum(int k) {
    for (int cnt = 0;; ++cnt) {
        if (getTriangleNum(cnt) > k) {
            return cnt - 1;
        }
    }
}

int isThreeSumOfTriangleNum(int num) {
    int maxTriangleNum = findMaxTriangleNum(num);

    for (int i = 1; i <= maxTriangleNum; ++i) {
        for (int j = i; j <= maxTriangleNum; ++j) {
            for (int k = i; k <= maxTriangleNum; ++k) {
                if (getTriangleNum(i) + getTriangleNum(j) + getTriangleNum(k) == num) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main() {
    int testCase;
    scanf("%d", &testCase);

    while (testCase--) {
        int num;
        scanf("%d", &num);

        printf("%d\n", isThreeSumOfTriangleNum(num));
    }
}