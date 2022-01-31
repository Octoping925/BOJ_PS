// https://www.acmicpc.net/problem/10757
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[10010], b[10002];
int answer[10010];

int toNumber(char x) { return x - '0'; }

int main()
{
    scanf("%s", a);
    scanf("%s", b);
    
    int a_len = strlen(a);
    int b_len = strlen(b);
    int max = a_len > b_len ? a_len : b_len;
    int olim = 0;
    
    for(int i = 0; i <= max; ++i)
    {
        answer[i] += olim;
        if(a_len - i - 1 >= 0) answer[i] += toNumber(a[a_len - i - 1]);
        if(b_len - i - 1 >= 0) answer[i] += toNumber(b[b_len - i - 1]);
        
        olim = answer[i] / 10;
        answer[i] %= 10;
    }
    

    if(answer[max] > 0)
        printf("%d", answer[max]);
        
    for(int i = max - 1; i >= 0; --i)
        printf("%d", answer[i]);
    
    return 0;
}