// https://www.acmicpc.net/problem/4153
#include <stdio.h>

int a, b, c;
int main()
{
    while(1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(a + b + c == 0) break;

        a *= a;
        b *= b;
        c *= c;
        if(a+b == c) printf("right\n");
        else if(b+c == a) printf("right\n");
        else if(a+c == b) printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}