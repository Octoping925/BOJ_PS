// https://www.acmicpc.net/problem/11815
#include <stdio.h>
#include <math.h>

int n;
long long x;

int main()
{
    scanf("%d", &n);
    
    while(n--) {
        scanf("%lld", &x);
        long long root = sqrt(x);
        printf("%d ", root*root == x);
    }

    return 0;
}