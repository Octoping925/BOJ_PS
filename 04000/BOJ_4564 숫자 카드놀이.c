// https://www.acmicpc.net/problem/4564
#include <stdio.h>

int getMultiply(int x) {
    if(x < 10) return 0;
    
    int ans = 1;
    while(x > 0) {
        ans *= x % 10;
        x /= 10;
    }
    return ans;
}

int main()
{
    int n;
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;
        
        while(n > 9) {
            printf("%d ", n);
            n = getMultiply(n);
        }
        printf("%d\n", n);
    }
}