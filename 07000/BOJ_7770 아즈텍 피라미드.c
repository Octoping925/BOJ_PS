// https://www.acmicpc.net/problem/7770
#include <stdio.h>

int n;

int main()
{
    scanf("%d", &n);

    if(n < 6) {
        printf("1");
        return 0;
    }

    int answer = 1;
    int floor = 1;
    int i = 1;

    do {
        ++i;
        answer += floor +  4 * (i-2) + 4;
        floor += 4 * (i-2) + 4;
    } while(answer <= n);

    printf("%d", i-1);
    return 0;
}