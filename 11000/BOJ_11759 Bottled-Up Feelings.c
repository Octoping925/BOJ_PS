// https://www.acmicpc.net/problem/11759
#include <stdio.h>

int main() {
    int s, v1, v2;
    scanf("%d %d %d", &s, &v1, &v2);

    int max = s / v1;

    for(int i = max; i >= 0; --i) {
        int leftAmount = s - v1 * i;

        if(leftAmount % v2 == 0) {
            printf("%d %d", i, leftAmount / v2);
            return 0;
        }
    }

    printf("Impossible");
    return 0;
}