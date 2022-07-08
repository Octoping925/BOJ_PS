// https://www.acmicpc.net/problem/15351
#include <stdio.h>
#include <string.h>

int n;
char str[31];

int main()
{
    scanf("%d\n", &n);
    while(n--) {
        gets(str);

        int score = 0;
        for(int i = 0; i < strlen(str); ++i) {
            score += str[i] != ' ' ? str[i] - 'A' + 1 : 0;
        }

        if(score == 100) printf("PERFECT LIFE\n");
        else printf("%d\n", score);
    }

    return 0;
}