// https://www.acmicpc.net/problem/2748
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    long long a=0, b=0, c=1, tmp;
    int cnt = 1;
    while(cnt < n)
    {
        a = b;
        tmp = c;
        c = b + c;
        b = tmp;
        ++cnt;
    }
    printf("%lld", c);
}


// c => b+c
// b => c
// a => b