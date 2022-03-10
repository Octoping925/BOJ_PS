// https://www.acmicpc.net/problem/1654
#include <stdio.h>

int str[10010];
int n, k;

long min(long x, long y) { return x < y ? x : y; }

long f(int x)
{
    long sum = 0;
    for(int j = 0; j < n; ++j)
        sum += str[j] / x;
    return sum;
}

int main()
{
    scanf("%d %d", &n, &k);

    long l, r = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &str[i]);
        if(str[i] > r) r = str[i];
    }
    l = r/k;
    
    while(l < r)
    {
        long mid = (l + r) / 2;
        if(mid == 0) ++mid;
        
        if(f(mid) < k) {
            r = mid - 1;
        }
        else {
            l = mid;
            if(f(r) < k) --r;
            else l = r;
        }
    }

    printf("%ld", (l + r) / 2);
    return 0;
}