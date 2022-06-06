// https://www.acmicpc.net/problem/24416
#include <stdio.h>

int fibo[41];

void findFibo(int n) {
    fibo[1] = fibo[2] = 1;
    for(int i = 3; i <= n; ++i) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    findFibo(n);
    printf("%d %d", fibo[n], n-2);
}