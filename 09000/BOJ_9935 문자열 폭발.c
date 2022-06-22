// https://www.acmicpc.net/problem/9935
#include <stdio.h>
#include <string.h>

char txt[1000010];
char explode[37];
char stack[1000010];
int top = -1;
int explode_idx = 0;

int max(int x, int y) {
    return x > y ? x : y;
}

int main()
{
    scanf("%s", txt);
    scanf("%s", explode);
    int txt_len = strlen(txt);
    int explode_len = strlen(explode);

    for(int i = 0; i < txt_len; ++i) {
        stack[++top] = txt[i];

        if(stack[top] == explode[explode_idx]) {
            ++explode_idx;
        }
        else {
            explode_idx = 0;
            if(stack[top] == explode[0]) {
                explode_idx++;
            }
        }

        if(explode_idx == explode_len) {
            top -= explode_len;
            explode_idx = 0;

            if(top > -1) {
                for(int j = max(top-explode_len, 0); j <= top; ++j) {
                    if(stack[j] == explode[explode_idx]) {
                        explode_idx++;
                    }
                    else {
                        explode_idx = stack[j] == explode[0] ? 1 : 0;
                    }
                }
            }
        }
    }

    if(top == -1) {
        printf("FRULA");
    }
    else {
        for(int i = 0; i <= top; ++i) {
            printf("%c", stack[i]);
        }
    }
}