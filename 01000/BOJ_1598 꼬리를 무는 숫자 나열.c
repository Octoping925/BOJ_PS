// https://www.acmicpc.net/problem/1598
#include <stdio.h>

int abs(int x) { return x > 0 ? x : -x; }

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    if(x > y) {
        int tmp = y;
        y = x;
        x = tmp;
    }

    int uplen = abs(y%4 - x%4);

    y -= y%4;
    x -= x%4;
    int rightlen = (y-x) / 4;
    printf("%d", uplen + rightlen);
}