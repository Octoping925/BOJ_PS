// https://www.acmicpc.net/problem/13752
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; ++j) {
            printf("=");
        }
        printf("\n");
    }
}
