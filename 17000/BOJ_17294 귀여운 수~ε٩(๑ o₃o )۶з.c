// https://www.acmicpc.net/problem/17294
#include <stdio.h>
#include <string.h>

char num[20];

int main()
{
    scanf("%s", num);

    int len = strlen(num);    
    if(len > 2) {
        int d = num[1] - num[0];
        for(int i = 2; i < len; ++i) {
            if(num[i] - num[i - 1] != d) {
                printf("흥칫뿡!! <(￣ ﹌ ￣)>");
                return 0;
            }
        }
    }

    printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
    return 0;
}