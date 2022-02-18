// https://www.acmicpc.net/problem/15624
#include <stdio.h>
 
long a[1000001];
 
void f(int x) {
    a[0] = 0, a[1] = 1;
    for (int i = 2; i <= x; ++i)
        a[i] = (a[i - 1] + a[i - 2]) % 1000000007;
    printf("%ld", a[x]);
}
 
int main() {
    int n;
    scanf("%d", &n);
    f(n);
}