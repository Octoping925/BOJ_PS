// https://www.acmicpc.net/problem/24417
// #include <stdio.h>

long long fibo(int x) {
    if(x >= 1500000) return fibo(x % 1500000);
    long long a[1500001];
    a[0] = 0, a[1] = 1;
    for (int i = 2; i <= x; ++i)
        a[i] = (a[i - 1] + a[i - 2]) % 1000000007;
    return a[x];
}

int main() {
    long long n;
    scanf("%lld", &n);
    f(n % 1500000);
}


int main()
{
    int n;
    scanf("%d", &n);

    printf("%lld %d", fibo(n), (n-2) % 1000000007);
}