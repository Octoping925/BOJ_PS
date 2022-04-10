// https://www.acmicpc.net/problem/15873
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if(n < 100) printf("%d", n/10 + n%10);
    else if(n < 1000) printf("%d", n/10 == 10 ? 100 + n%10 : n/100 + 10);
    else printf("%d", n/100 + n%100);
    return 0;
}