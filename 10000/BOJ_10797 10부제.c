// https://www.acmicpc.net/problem/10797
#include <stdio.h>
int n, m, a;
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < 5; ++i) {
        scanf("%d", &m);
        if(m == n) a++;
    }
    printf("%d", a);
}