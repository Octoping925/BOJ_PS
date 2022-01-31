// https://www.acmicpc.net/problem/2562
#include <stdio.h>

int main()
{
    int max = -1, cnt = 1;
    for(int i = 0; i < 9; ++i)
    {
        int k;
        scanf("%d", &k);
        if(k > max) {
            max = k;
            cnt = i + 1;
        }
    }
    printf("%d\n%d", max, cnt);
}