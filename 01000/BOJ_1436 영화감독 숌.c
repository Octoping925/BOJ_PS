// https://www.acmicpc.net/problem/1436
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int cnt = 0, i = 665;
    while(cnt < n)
    {
        int tmp = ++i;
        while(tmp > 665)
        {
            if(tmp % 1000 == 666) {
                cnt++;
                break;
            }
            tmp /= 10;
        }
    }
    printf("%d", i);
}