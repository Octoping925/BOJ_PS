// https://www.acmicpc.net/problem/15927
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char txt[500010];

int main()
{
    scanf("%s", txt);

    bool allSame = true;
    bool isPalindrome = true;
    char firstLetter = txt[0];

    int len = strlen(txt);
    for(int i = 0; i < len; ++i)
    {
        if(txt[i] != firstLetter) {
            allSame = false;
        }
        if(txt[i] != txt[len - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if(!isPalindrome) {
        printf("%d", len);
    }
    else if(allSame) {
        printf("-1");
    }
    else {
        printf("%d", len - 1);
    }
}

/*

 문자열의 경우 3가지 경우가 있음

1. 전부 똑같은 문자일 경우, 무조건 -1
2. 회문이 아닌 문자일 경우, 해당 문자열의 길이가 정답

3. 전부 똑같은 문자가 아니면서 회문일 경우, 해당 문자열에서 마지막 글자 하나만 빼도 회문이 아니게 됨.
따라서 '해당 문자열의 길이 - 1'이 정답

 */