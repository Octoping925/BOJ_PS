// https://www.acmicpc.net/problem/14409
#include <stdio.h>
#include <stdlib.h>

int max(int x, int y) { return x > y ? x : y; }
int main()
{
    int n, x;
    scanf("%d\n%d", &n, &x);

    int sum = 0;
    while(n--) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(abs(a-b) > x) {
            scanf("%d", &a);
            sum += a;
        }
        else sum += max(a, b);
    }
    printf("%d", sum);
}