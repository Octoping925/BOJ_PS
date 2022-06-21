// https://www.acmicpc.net/problem/11023
#include <stdio.h>
int sum, n;
int main()
{
    for(; ~scanf("%d", &n);) {
        sum += n;
    }
    printf("%d", sum);
}