// https://www.acmicpc.net/problem/23811
#include <stdio.h>

void printGaro(int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 5 * n; ++j) {
            printf("@");
        }
        printf("\n");
    }
}

void printSero(int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("@");
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    printGaro(n);
    printSero(n);
    printGaro(n);
    printSero(n);
    printGaro(n);

    return 0;
}
