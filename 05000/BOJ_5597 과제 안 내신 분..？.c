// https://www.acmicpc.net/problem/5597
#include <stdio.h>

int count[31];

int main() {
    for(int i = 0, k; i < 28; ++i) {
        scanf("%d", &k);
        count[k]++;
    }
    for(int i = 1; i <= 30; ++i) {
        if(!count[i]) {
            printf("%d\n", i);
        }
    }
}