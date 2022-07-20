// https://www.acmicpc.net/problem/13268
#include <stdio.h>

int cycleTotal = 100;
int n;

int main()
{
    scanf("%d", &n);
    n %= cycleTotal;

    for(int dis = 5; dis <= 20; dis += 5) {
        if(n < dis) {
            printf("%d", (n+4) / 5);
            break;
        }
        n -= dis;
        if(n < dis) {
            printf("%d", (dis - n + 4) / 5);
            break;
        }
        n -= dis;
    }

    return 0;
}