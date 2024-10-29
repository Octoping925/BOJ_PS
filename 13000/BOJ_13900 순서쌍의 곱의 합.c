// https://www.acmicpc.net/problem/13900
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100001];
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    long long result = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0) continue;

        sum -= arr[i];
        result += (long long) arr[i] * sum;
    }

    printf("%lld", result);
}
