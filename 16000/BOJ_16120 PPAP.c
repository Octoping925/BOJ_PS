// https://www.acmicpc.net/problem/16120
#include <stdio.h>
#include <string.h>

char txt[1000010];
char stack[1000010];
char ppap[4] = {'P','P','A','P'};

int txt_len, ppap_idx, top = -1;

int main()
{
    scanf("%s", txt);
    txt_len = strlen(txt);

    for(int i = 0; i < txt_len; ++i) {
        stack[++top] = txt[i];

        if(stack[top] == ppap[ppap_idx]) {
            ++ppap_idx;
        }
        else {
            if(stack[top] == 'P') {
                if(stack[top-1] == 'P') ppap_idx = 2;
                else ppap_idx = 1;
            }
            else ppap_idx = 0;
        }

        if(ppap_idx == 4) {
            top -= 3; // PAP
            if(top > 0 && stack[top - 1] == 'P') {
                ppap_idx = 2;
            }
            else ppap_idx = 1;
        }
    }

    if(top == 0 && stack[top] == 'P') {
        printf("PPAP");
    }
    else {
        printf("NP");
    }
}