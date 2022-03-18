// https://www.acmicpc.net/problem/2023
#include <stdio.h>

int n;

int sosu(int x)
{
    for(int i = 3; i*i <= x; ++i) {
        if(x % i == 0) return 0;
    }
    return 1;
}

int concat(int x, int y) { return x * 10 + y; }

void back(int num, int depth)
{
    if(!sosu(num)) return;

    if(depth == n) {
        printf("%d\n", num);
        return;
    }

    for(int i = 1; i < 10; i += 2) {
        back(concat(num, i), depth + 1);
    }
}

int main()
{
    scanf("%d", &n);
    back(2, 1);
    back(3, 1);
    back(5, 1);
    back(7, 1);
    return 0;
}