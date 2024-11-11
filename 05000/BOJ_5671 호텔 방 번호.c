// https://www.acmicpc.net/problem/5671
#include <stdio.h>

int isDuplicateNumber(int x) {
    int bitmask = 0;

    while (x > 0) {
        int k = x % 10;

        if (bitmask & (1 << k)) {
            return 1;
        }

        bitmask |= (1 << k);
        x /= 10;
    }

    return 0;
}

int main() {
    int n, m;

    while (~scanf("%d %d", &n, &m)) {
        int cnt = 0;
        for (int i = n; i <= m; ++i) {
            if (!isDuplicateNumber(i)) ++cnt;
        }

        printf("%d\n", cnt);
    }
}
