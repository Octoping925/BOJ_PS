// https://www.acmicpc.net/problem/11134
#include <stdio.h>
#define min(x,y) (x < y ? x : y)

int tc;
int n, c;

int main()
{
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &n, &c);
        printf("%d\n", n/c + min(n % c, 1));
    }
}