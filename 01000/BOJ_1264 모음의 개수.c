// https://www.acmicpc.net/problem/1264
#include <stdio.h>
#include <string.h>

char txt[257];

int main() {
    while(1) {
        gets(txt);
        if(txt[0] == '#') break;

        int cnt = 0;
        int len = strlen(txt);
        for(int i = 0; i < len; i++) {
            if('A' <= txt[i] && txt[i] <= 'Z') txt[i] = txt[i] - 'A' + 'a';
            if(txt[i] == 'a' || txt[i] == 'e' || txt[i] == 'i' || txt[i] == 'o' || txt[i] == 'u') {
                cnt++;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}