// https://www.acmicpc.net/problem/15734
#include <stdio.h>

int abs(int x) { return x > 0 ? x : -x; }

int main()
{
    int l, r, a;
    scanf("%d %d %d", &l, &r, &a);

    int diff = abs(l - r);

    if(diff >= a) {
        printf("%d", l+r+a - (diff-a));
    }
    else {
        printf("%d", l+r+a - (a-diff)%2);
    }
}