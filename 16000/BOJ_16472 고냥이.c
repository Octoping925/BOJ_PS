#include <stdio.h>
#include <string.h>

char txt[100010];
int alpha[26];
size_t len;

int n;
int pointer1;
int pointer2;
int cnt = 1;

int max(int x, int y) {
    return x > y ? x : y;
}

void addPointer1() {
    --alpha[txt[pointer1] - 'a'];
    if(alpha[txt[pointer1] - 'a'] == 0) {
        --cnt;
    }
    ++pointer1;
}
void addPointer2() {
    ++pointer2;
    if(alpha[txt[pointer2] - 'a'] == 0) {
        ++cnt;
    }
    ++alpha[txt[pointer2] - 'a'];
}

int main()
{
    scanf("%d", &n);
    scanf("%s", txt);
    len = strlen(txt);

    int maxLen = 0;
    alpha[txt[0]-'a'] = 1;
    while(pointer1 < len-1) {
        if(pointer1 == pointer2 || (cnt < n && pointer2 < len - 1)) {
            addPointer2();
        }
        else if(cnt > n) {
            addPointer1();
        }
        else {
            maxLen = max(maxLen, pointer2 - pointer1 + 1);
            if(pointer2 < len-1 && alpha[txt[pointer2+1]-'a']) addPointer2();
            else addPointer1();
        }
    }

    printf("%d", maxLen);
    return 0;
}
