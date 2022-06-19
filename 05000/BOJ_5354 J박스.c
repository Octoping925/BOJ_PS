// https://www.acmicpc.net/problem/5354
#include <stdio.h>

void printLine(int k) {
    for(int i = 0; i < k; ++i) {
        printf("#");
    }
    printf("\n");
}

void printCenter(int k) {
    printf("#");
    for(int i = 1; i < k-1; ++i) {
        printf("J");
    }
    printf("#");
    printf("\n");

}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--) {
        int k;
        scanf("%d", &k);

        printLine(k);
        for(int i = 1; i < k-1; ++i) printCenter(k);
        if(k != 1) printLine(k);
        printf("\n");
    }
}