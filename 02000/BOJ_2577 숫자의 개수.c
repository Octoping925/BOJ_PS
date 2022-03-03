// https://www.acmicpc.net/problem/2577
#include <stdio.h>
int a[10];
int main()
{
    int t = 1;
    for(int i = 0; i < 3; ++i) {
        int k;
        scanf("%d", &k);
        t *= k;
    }
    
    while(t > 10) {
        ++a[t % 10];
        t /= 10;
    }
    a[t]++;
    
    for(int i = 0; i < 10; ++i) {
        printf("%d\n", a[i]);
    }
}