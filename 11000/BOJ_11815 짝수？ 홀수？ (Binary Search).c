// https://www.acmicpc.net/problem/11815
#include <stdio.h>
#define min(x, y) (x < y ? x : y)

int n;
long long x;

int findSqrt(long long x) {
    int left = 1;
    int right = min(x, 1e9);
    int isFind = 0;

    while(left <= right) {
        long long mid = (left + right) / 2;
        long long prime = mid * mid;

        if(prime == x) {
            isFind = 1;
            break;
        }
        else if(prime > x) {
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }

    return isFind;
}

int main()
{
    scanf("%d", &n);
    
    while(n--) {
        scanf("%lld", &x);
        printf("%d ", findSqrt(x));
    }

    return 0;
}