// https://www.acmicpc.net/problem/2688
#include <stdio.h>

long long answer;

int main()
{
    int T, n;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        scanf("%d", &n);
        int left = n + 9, right = n;
        if(right > 9) right = 9;

        long long up = 1;
        for(int j = left - right + 1; j <= left; ++j)
            up *= j;
        for(int j = 2; j <= right; ++j)
            up /= j;
        
        printf("%lld\n", up);
    }
}