// https://www.acmicpc.net/problem/27310
#include <stdio.h>
#include <string.h>

int main()
{
    char text[33];
    scanf("%s", text);

    int len = strlen(text);
    int result = 0;
    for(int i = 0; i < len; ++i) {
        if(text[i] == ':') {
            result += 1;
        }
        else if(text[i] == '_') {
            result += 5;
        }
    }

    result += len;

    printf("%d", result);

    return 0;
}