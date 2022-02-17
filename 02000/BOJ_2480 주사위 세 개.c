// https://www.acmicpc.net/problem/2480
#include <stdio.h>
int a, b, c;

int max(int a, int b, int c)
{
    int m;
        if(a > b)
            if(a > c) m = a;
            else m = c;
        else {
            if(b > c) m = b;
            else m = c;
        }
        return m;
}
int main()
{
    int ans;
    scanf("%d %d %d", &a, &b, &c);
    if(a==b && b==c) ans = 10000 + 1000 * a;
    else if(b == c || a == b) ans = 1000 + 100 * b;
    else if(a == c) ans = 1000 + 100 * c;
    else {
        ans = max(a, b, c) * 100;
    }

    printf("%d", ans);
}