// https://www.acmicpc.net/problem/20953
#include <stdio.h>

int dolmen(int a, int b) {
    return (a+b) * ((a+b)*(a+b-1)/2);
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", dolmen(a, b));
    }

    return 0;
}