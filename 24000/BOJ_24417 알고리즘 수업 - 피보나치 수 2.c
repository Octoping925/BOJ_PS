// https://www.acmicpc.net/problem/24417
#include <stdio.h>

int fibo(int x) {
    long a=1, b=2, c=3, tmp;
    for (int i = 5; i <= x; ++i) {
        tmp = b;
        b = c;
        a = tmp;
        c = (a+b) % 1000000007;
    }
    return c;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d %d", fibo(n), (n-2) % 1000000007);
}