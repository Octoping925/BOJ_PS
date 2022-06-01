// https://www.acmicpc.net/problem/1241
#include <stdio.h>

int input[100010], cnt[1000010], vector[100010], answer[1000010];

int main()
{
    int n;
    scanf("%d", &n);

    int size = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &input[i]);
        if(cnt[input[i]]++ == 0) vector[size++] = input[i];
    }

    for(int i = 0; i < size; ++i) {
        int p = vector[i];

        for(int j = 1; j*j <= p; ++j) {
            if(p % j == 0) {
                answer[p] += cnt[j] + cnt[p / j];
            }
            if(j*j == p) answer[p] -= cnt[j];
        }
    }

    for(int i = 0; i < n; ++i) {
        printf("%d\n", answer[input[i]] - 1);
    }

    return 0;
}