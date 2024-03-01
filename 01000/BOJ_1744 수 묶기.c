// https://www.acmicpc.net/problem/1744
#include <stdio.h>

int n, arr[51];

void sort() {
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (arr[j - 1] > arr[j]) {
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int getNegativeCount() {
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) k++;
    }

    return k;
}

int getPositiveCount() {
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) k++;
    }

    return k;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    sort();

    int negativeCount = getNegativeCount();
    int positiveCount = getPositiveCount();

    int res = 0;
    for (int i = 1; i < negativeCount; i += 2) {
        res += arr[i] * arr[i - 1];
    }

    if (negativeCount % 2 == 1) {
        int containsZero = n - negativeCount - positiveCount > 0;
        if (!containsZero) {
            res += arr[negativeCount - 1];
        }
    }

    for (int i = n - 2; i >= n - positiveCount; i -= 2) {
        if (arr[i] != 1) {
            res += arr[i] * arr[i + 1];
        } else {
            res += arr[i] + arr[i + 1];
        }
    }

    if (positiveCount % 2 == 1) {
        res += arr[n - positiveCount];
    }

    printf("%d", res);
}