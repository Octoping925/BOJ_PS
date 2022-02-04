// https://www.acmicpc.net/problem/1038
#include <stdio.h>

int gamso(long long x)
{
    int cnt = x % 10;
    x /= 10;
    while(x > 0)
    {
        if(cnt >= x % 10) return 0;
        cnt = x % 10;
        x /= 10;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    //printf("%d\n", gamso())
    if(n == 0) {
        printf("0");
        return 0;
    }
    if(n > 1022) {
        printf("-1");
        return 0;
    }

    int cnt = 0;
    long long i = 0;

    if(n < 175) { // 3자리
        cnt = 55;
        i = 210;
    }
    else if(n < 385) { // 4자리
        cnt = 175;
        i = 3210;
    }
    else if(n < 637){ // 5자리
        cnt = 385;
        i = 43210;
    }
    else if(n < 847){ // 6자리
        cnt = 637;
        i = 543210;
    }
    else if(n < 967){ // 7자리
        cnt = 847;
        i = 6543210;
    }
    else if(n < 1012){ // 8자리
        cnt = 967;
        i = 76543210;
    }
    else if(n < 1022){ // 9자리
        cnt = 1011;
        i = 876543210;
    }
    else { // 10자리
        cnt = 1022;
        i = 9876543210;
    }

    while(cnt < n)
    {
        ++i;
        if(gamso(i) == 1) {
            ++cnt;
            //if(cnt == n+1) break;
        }
        
    }
    printf("%lld", i);

}