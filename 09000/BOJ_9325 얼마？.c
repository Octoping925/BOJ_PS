// https://www.acmicpc.net/problem/9325
#include <stdio.h>

int main() {
    int testCase;
    scanf("%d", &testCase);

    while(testCase--) {
        int price;
        scanf("%d", &price);

        int options;
        scanf("%d", &options);

        while(options--) {
            int optionCount;
            int optionPrice;
            scanf("%d %d", &optionCount, &optionPrice);
            price += optionPrice * optionCount;
        }

        printf("%d\n", price);
    }
    
    return 0;
}