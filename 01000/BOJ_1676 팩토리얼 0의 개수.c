// https://www.acmicpc.net/problem/1676
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 5; i <= n; i += 5)
    {
        int tmp = i;
        while(tmp % 5 == 0) {
            cnt++;
            tmp /= 5;
        }
    }
    printf("%d", cnt);
}