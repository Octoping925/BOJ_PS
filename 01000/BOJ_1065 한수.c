// https://www.acmicpc.net/problem/1065
#include <stdio.h>

int chkDC(int x) {
    if(x < 10) return 1;
    
    int r = x % 10; 
    x /= 10;
    int d = r - x % 10;
    
    while(x) {
        if(r - x % 10 != d) return 0;
        r = x % 10;
        x /= 10;
    }
    return 1;
}

int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        if(chkDC(i)) sum++;
    }
    printf("%d", sum);
    return 0;
}
