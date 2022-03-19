// https://www.acmicpc.net/problem/2602
#include <stdio.h>
#include <string.h>

char word[21];
char angel[101];
char devil[101];

int angelDP[101][21];
int devilDP[101][21];

int main()
{
    scanf("%s", word);
    scanf("%s", devil);
    scanf("%s", angel);

    int wordLen = strlen(word);
    int bridgeLen = strlen(angel);

    for(int i = 0; i < bridgeLen; ++i)
    {
        // devil 구하기
        if(word[0] == devil[i]) ++devilDP[i][0];

        for(int j = 1; j < wordLen; ++j)
        {
            if(word[j] != devil[i]) continue;

            for(int k = 0; k < i; ++k)
            {
                if(word[j - 1] == angel[k]) {
                    devilDP[i][j] += angelDP[k][j - 1];
                }
            }
            
        }
        // angel 구하기
        if(word[0] == angel[i]) ++angelDP[i][0];

        for(int j = 1; j < wordLen; ++j)
        {
            if(word[j] != angel[i]) continue;

            for(int k = 0; k < i; ++k)
            {
                if(word[j - 1] == devil[k]) {
                    angelDP[i][j] += devilDP[k][j - 1];
                }
            }
            
        }
    }


    int sum = 0;
    for(int i = 0; i < bridgeLen; ++i)
    {
        sum += devilDP[i][wordLen - 1];
        sum += angelDP[i][wordLen - 1];
    }

    printf("%d", sum);
}