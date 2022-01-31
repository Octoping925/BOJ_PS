// https://www.acmicpc.net/problem/5622
#include <stdio.h>
#include <string.h>

char txt[20];

int main()
{
    scanf("%s", txt);
    int len = strlen(txt);
    int sum = 0;
    
    for(int i = 0; i < len; ++i)
    {
        int cnt = txt[i] - 'A';
        int num;
        
        if(cnt < 3) num = 2;
        else if(cnt < 6) num = 3;
        else if(cnt < 9) num = 4;
        else if(cnt < 12) num = 5;
        else if(cnt < 15) num = 6;
        else if(cnt < 19) num = 7;
        else if(cnt < 22) num = 8;
        else if(cnt < 26) num = 9;
        
        sum += num + 1;
    }
    
    printf("%d", sum);
}