// https://www.acmicpc.net/problem/13458
#include <stdio.h>

int stage[1000001];

int max(int x, int y) {
    return x > y ? x : y;
}

int upper(double x) {
    int intX = (int) x;
    if(x == intX) return intX;
    return intX + 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &stage[i]);
    }

    int b, c;
    scanf("%d %d", &b, &c);

    long long result = 0;
    for(int i = 0; i < n; ++i) {
        int subDirector = upper((double)(max(stage[i] - b, 0)) / c);
        result += 1 + subDirector;
    }

    printf("%lld", result);
    return 0;
}