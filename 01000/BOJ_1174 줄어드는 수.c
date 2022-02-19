// https://www.acmicpc.net/problem/1174
#include <stdio.h>

int jul(long x) {
    if(x <= 10) return 1;
    while(1)
    {
        int k = x % 10;
        x /= 10;
        if(x == 0) return 1;
        if(x % 10 <= k) return 0;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    if(n > 1023) printf("-1");
    else
    {
        long ans = -1;
        int cnt = 1;
        if(n <= 10) ans = 0, cnt = 1;
        else if(n <= 55)  ans= 10, cnt = 11;
        else if(n <= 175) ans = 210, cnt = 56;
        else if(n <= 385) ans = 3210,  cnt= 176;
        else if(n <= 637) ans = 43210,  cnt= 386;
        else if(n <= 847) ans = 543210,  cnt= 638;
        else if(n <= 967) ans = 6543210,  cnt= 848;
        else if(n <= 1012) ans = 76543210, cnt = 968;
        else if(n <= 1022) ans = 876543210, cnt = 1013;
        else if(n <= 1023) ans = 9876543210, cnt = 1023;

        ans--;

        while(cnt <= n)
            cnt += jul(++ans);

        printf("%ld", ans);
    }
}