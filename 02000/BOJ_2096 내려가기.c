// https://www.acmicpc.net/problem/2096
#include <stdio.h>

int max(int x, int y, int z) {
    if(x > y && x > z) return x;
    if(y > z) return y;
    return z;
}
int min(int x, int y, int z) {
    if(x < y && x < z) return x;
    if(y < z) return y;
    return z;
}

int n;

int main()
{
    scanf("%d", &n);

    int window[3];
    int maxArr[3] = {0,0,0};
    int minArr[3] = {0,0,0};

    int a1, a2, a3;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d %d", &window[0], &window[1], &window[2]);
        a1 = window[0] + max(maxArr[0], maxArr[1], -1);
        a2 = window[1] + max(maxArr[0], maxArr[1], maxArr[2]);
        a3 = window[2] + max(-1,        maxArr[1], maxArr[2]);
        maxArr[0] = a1;
        maxArr[1] = a2;
        maxArr[2] = a3;

        a1 = window[0] + min(minArr[0], minArr[1], 10000000);
        a2 = window[1] + min(minArr[0], minArr[1], minArr[2]);
        a3 = window[2] + min(10000000,  minArr[1], minArr[2]);
        minArr[0] = a1;
        minArr[1] = a2;
        minArr[2] = a3;
    }

    printf("%d %d", max(maxArr[0], maxArr[1], maxArr[2]), min(minArr[0], minArr[1], minArr[2]));
    return 0;
}