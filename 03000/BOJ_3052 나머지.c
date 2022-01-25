// https://www.acmicpc.net/problem/3052
#include <stdio.h>

int cnt[43];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
        ++cnt[n % 42];
        
    int s = 0;
    for(int i = 0; i < 43; ++i) {
        if(cnt[i]) s++;
    }
    printf("%d", s);
    return 0;
}
