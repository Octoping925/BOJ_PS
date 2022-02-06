// https://www.acmicpc.net/problem/11729
#include <stdio.h>
#include <math.h>

void hanoi(int x, int start, int mid, int to)
{
    if(x == 1) {
        printf("%d %d\n", start, to);
        return;
    }
    hanoi(x - 1, start, to, mid);
    printf("%d %d\n", start, to);
    hanoi(x - 1, mid, start, to);
}

void sol(int x)
{
    printf("%d\n", (int)pow(2, x) - 1);
    hanoi(x, 1, 2, 3);
}

int main()
{
    int n;
    scanf("%d", &n);
    sol(n);
}