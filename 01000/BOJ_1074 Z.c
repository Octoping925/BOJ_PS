// https://www.acmicpc.net/problem/1074
#include <stdio.h>

int n, r, c;

int func(int leftX, int leftY, int rightX, int rightY)
{
    int len = (rightX - leftX + 1);
    if(len == 1) return 1;

    int midX = (leftX + rightX) / 2;
    int midY = (leftY + rightY) / 2;

    len /= 2;
    if(r <= midX && c <= midY) return func(leftX, leftY, midX, midY);
    else if(r > midX && c <= midY) return len*len + func(midX + 1, leftY, rightX, midY);
    else if(r <= midX && c > midY) return len*len * 2 + func(leftX, midY + 1, midX, rightY);
    return len*len * 3 + func(midX + 1, midY + 1, rightX, rightY);
}

int main()
{
    scanf("%d %d %d", &n, &c, &r);
    printf("%d", func(0, 0, (1 << n) - 1, (1 << n) - 1) - 1);
}