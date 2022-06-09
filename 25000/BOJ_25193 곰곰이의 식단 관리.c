// https://www.acmicpc.net/problem/25193
#include <stdio.h>

int c, nc;

int upify(double x) {
    if(x - (int)x == 0) return (int)x;
    return (int)x + 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--) {
        char k;
        scanf(" %c", &k);
        if(k == 'C') c++;
        else nc++;
    }

    printf("%d", upify((double) c / (nc + 1)));
    return 0;
}