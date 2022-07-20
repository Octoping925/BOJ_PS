// https://www.acmicpc.net/problem/16162
#include <stdio.h>

int n, a, d;
int x;

int main()
{
    scanf("%d %d %d", &n, &a, &d);

    while(n--) {
        int k;
        scanf("%d", &k);

        if(k == a) {
            x++;
            a += d;
        }
    }

    printf("%d", x);
    return 0;
}