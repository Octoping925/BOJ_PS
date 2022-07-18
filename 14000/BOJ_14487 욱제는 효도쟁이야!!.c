// https://www.acmicpc.net/problem/14487
#include <stdio.h>

int n, sum, max;

int main()
{
    scanf("%d", &n);

    while(n--) {
        int k;
        scanf("%d", &k);
        if(k > max) {
            max = k;
        }
        sum += k;
    }

    printf("%d", sum - max);
    return 0;
}