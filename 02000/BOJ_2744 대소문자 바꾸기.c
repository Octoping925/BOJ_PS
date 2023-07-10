// https://www.acmicpc.net/problem/2744
#include <stdio.h>
#include <string.h>

int main() {
    char txt[101];
    scanf("%s", txt);

    int len = strlen(txt);
    for(int i = 0; i < len; ++i) {
        if(txt[i] >= 'a') {
            printf("%c", txt[i] - 'a' + 'A');
        }
        else {
            printf("%c", txt[i] - 'A' + 'a');
        }
    }
}