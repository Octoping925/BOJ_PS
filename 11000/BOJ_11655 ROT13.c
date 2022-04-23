// https://www.acmicpc.net/problem/11655
#include <stdio.h>
#include <string.h>

char txt[101];

char move(char k) {
    if('a' <= k && k <= 'z') return ((k - 'a') + 13) % 26 + 'a';
    if('A' <= k && k <= 'Z') return ((k - 'A') + 13) % 26 + 'A';
    return k;
}

int main()
{
    gets(txt);
    for(int i = 0; i < strlen(txt); ++i) {
        printf("%c", move(txt[i]));
    }
}