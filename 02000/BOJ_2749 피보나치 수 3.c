// https://www.acmicpc.net/problem/2749
#include <stdio.h>
 
long long a[1500001];
 
void f(int x) {
    a[0] = 0, a[1] = 1;
    for (int i = 2; i <= x; ++i)
        a[i] = (a[i - 1] + a[i - 2]) % 1000000;
    printf("%lld", a[x]);
}
 
int main() {
    long long n;
    scanf("%lld", &n);
    f(n % 1500000);
}
