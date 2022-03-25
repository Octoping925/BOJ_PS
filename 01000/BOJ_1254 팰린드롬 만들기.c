// https://www.acmicpc.net/problem/1254
#include <stdio.h>
#include <string.h>

char txt[51];
char arr[101];
int len;

int check(int l)
{
    for(int i = 0; i < l/2; ++i)
        if(arr[i] != arr[l - i - 1])
            return 0;
    return 1;
}

void concat(int l)
{
    for(int i = 0; i < len; ++i)
        arr[i] = txt[i];
    for(int i = 0; i < l; ++i)
        arr[len + l-i-1] = txt[i];
}

int main()
{
    scanf("%s", txt);
    len = strlen(txt);

    for(int i = 0; i < len; ++i) {
        concat(i);
        if(check(len+i)) {
            printf("%d", len+i);
            break;
        }
    }
    
    return 0;
}