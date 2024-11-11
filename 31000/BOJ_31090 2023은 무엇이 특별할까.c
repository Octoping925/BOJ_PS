// https://www.acmicpc.net/problem/31090
#include <stdio.h>

int main() {
    int t, n;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        printf("%s\n", (n+1) % (n % 100) == 0 ? "Good" : "Bye");
    }
}