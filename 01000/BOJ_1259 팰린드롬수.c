// https://www.acmicpc.net/problem/1259
#include <stdio.h>
#include <string.h>

int main()
{
    char n[6];
    while(1) {
        gets(n);
        if(n[0] == '0') break;

        int chk = 1;
        int len = strlen(n);
        for(int i = 0; i < len; ++i) {
            if(n[i] != n[len - i - 1]) {
                chk = 0;
                break;
            }
        }

        printf("%s\n", chk ? "yes" : "no");
    }
}