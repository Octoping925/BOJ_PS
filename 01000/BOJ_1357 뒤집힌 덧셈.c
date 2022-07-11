// https://www.acmicpc.net/problem/1357
#include <stdio.h>

int x, y;

int rev(int x) {
    int result = 0;
    while (x > 0) {
        result *= 10;
        result += x % 10;
        x /= 10;
    }
    return result;
}

int main()
{
    scanf("%d %d", &x, &y);
    printf("%d", rev(rev(x) + rev(y)));
    return 0;
}