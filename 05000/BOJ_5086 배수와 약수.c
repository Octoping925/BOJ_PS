// https://www.acmicpc.net/problem/5086
#include <stdio.h>

int main()
{
    while(1) {
        int n, k;
        scanf("%d %d", &n, &k);

        if(n == 0) return 0;
        if(n % k == 0) printf("multiple\n");
        else if(k % n == 0) printf("factor\n");
        else printf("neither\n");
    }
}9