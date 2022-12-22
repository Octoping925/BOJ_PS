// https://www.acmicpc.net/problem/1094
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int cnt = 0;
    for(int i = 1; i <= 64; i <<= 1) {
        if(n & i) {
            cnt++;
        }
    }

    printf("%d", cnt);
}