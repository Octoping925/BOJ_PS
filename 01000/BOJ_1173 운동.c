// https://www.acmicpc.net/problem/1173
#include <stdio.h>

int N, m, M, T, R;

int max(int x, int y) {
    return x > y ? x : y;
}

int main()
{
    scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);

    int time = 0;
    int now = m;

    if(m+T > M) {
        printf("-1");
        return 0;
    }

    while(N > 0) {
        time++;
        if(now+T <= M) {
            N--;
            now += T;
        }
        else {
            now = max(now-R, m);
        }
    }
    printf("%d", time);
}