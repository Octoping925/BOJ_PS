// https://www.acmicpc.net/problem/2941
#include <stdio.h>
#include <string.h>

char txt[110];

int func(char k, int i)
{
    if(k == 'c')
    {
        if(txt[i] == '=' || txt[i] == '-') return 1;
    }
    if(k == 'd')
    {
        if(txt[i] == 'z' && txt[i + 1] == '=') return 2;
        if(txt[i] == '-') return 1;
    }
    if(k == 'l' || k == 'n')
    {
        if(txt[i] == 'j') return 1;
    }
    if(k == 's' || k == 'z')
    {
        if(txt[i] == '=') return 1;
    }
    return 0;
}


int main()
{
    scanf("%s", txt);
    int cnt = 0;
    
    for(int i = 0; i < strlen(txt); ++i)
    {
        int chk = 0;
        switch(txt[i])
        {
            case 'c': case 'd': case 'l': 
            case 'n': case 's': case 'z':
                chk = func(txt[i], i + 1);
        }
        
        ++cnt;
        i += chk;
    }
    printf("%d", cnt);
}