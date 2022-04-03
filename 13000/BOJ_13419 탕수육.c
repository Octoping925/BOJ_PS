// https://www.acmicpc.net/problem/13419
#include <stdio.h>
#include <string.h>

char txt[30];
int n;

int main()
{
    scanf("%d", &n);
    while(n--) {
        scanf("%s", txt);
        int len = strlen(txt);

        if(len%2 == 0) {
            for(int i = 0; i < len; i += 2)
                printf("%c", txt[i]);
            printf("\n");
            for(int i = 1; i < len; i += 2)
                printf("%c", txt[i]);
        }

        else {
            for(int i = 0; i < len * 2; i += 2)
                printf("%c", txt[i%len]);
            printf("\n");
            for(int i = 1; i < len * 2; i += 2)
                printf("%c", txt[i%len]);
        }
        printf("\n");
    }
}