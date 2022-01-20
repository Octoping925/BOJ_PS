// https://www.acmicpc.net/problem/1157
#include <stdio.h>

int abc[30];

int main()
{
    char t;
    while(scanf("%c", &t) != EOF)
    {
        if('a' <= t && t <= 'z') {
            ++abc[t - 'a'];
        }
        else if('A' <= t && t <= 'Z') {
            ++abc[t - 'A'];
        }
    }
    
    int max = 0, cnt = 0;
    for(int i = 0; i <= 26; ++i) {
        if(abc[i] > abc[max]) {
            max = i;
            cnt = 1;
        }
        else if(abc[i] == abc[max]) {
            ++cnt;
        }
    }
    
    printf("%c", cnt == 1 ? max + 'A' : '?');
    return 0;
}