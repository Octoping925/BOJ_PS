// https://www.acmicpc.net/problem/24389
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int k = ~n + 1;

    int cnt = 0;
    for (int i = 0; i < 32; ++i) {
        int check1 = n & (1 << i);
        int check2 = k & (1 << i);

        if (check1 != check2) ++cnt;
    }

    printf("%d", cnt);
}