// https://www.acmicpc.net/problem/2747
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a=0, b=0, c=1, tmp, cnt = 1;
    while(cnt < n)
    {
        a = b;
        tmp = c;
        c = b + c;
        b = tmp;
        ++cnt;
    }
    printf("%d", c);
}


// c => b+c
// b => c
// a => b