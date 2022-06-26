// https://www.acmicpc.net/problem/6219
#include <stdio.h>

int prime[4000010];

void erathos() {
    for(int i = 2; i <= 4000000; ++i) {
        if(!prime[i]) {
            for(int j = i+i; j <= 4000000; j+=i) {
                prime[j] = 1;
            }
        }
    }
}

int isContain(int n, int d) {
    while(n > 0) {
        if(n % 10 == d) return 1;
        n /= 10;
    }
    return 0;
}

int main()
{
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);

    erathos();

    int cnt = 0;
    for(int i = a; i <= b; ++i) {
        if(!prime[i] && isContain(i, d)) {
            cnt++;
        }
    }

    printf("%d", cnt);
}