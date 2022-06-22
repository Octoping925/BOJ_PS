// https://www.acmicpc.net/problem/11365
#include <stdio.h>
#include <string.h>

char txt[501];

int main()
{
    while(1) {
        gets(txt);
        int len = strlen(txt);

        if(len == 3 && (txt[0] == 'E' && txt[1] == 'N' && txt[2] == 'D')) break;

        for(int i = len-1; i >= 0; --i) {
            printf("%c", txt[i]);
        }
        printf("\n");
    }
}