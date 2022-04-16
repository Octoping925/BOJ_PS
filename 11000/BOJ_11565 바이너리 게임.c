#include <stdio.h>
#include <string.h>

char txt1[1001];
char txt2[1001];

int main()
{
    scanf("%s\n%s", txt1, txt2);
    int len1 = strlen(txt1);
    int len2 = strlen(txt2);

    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < len1; ++i) {
        if(txt1[i] == '1') {
            cnt1++;
        }
    }
    for(int i = 0; i < len2; ++i) {
        if(txt2[i] == '1') {
            cnt2++;
        }
    }

    if(cnt1 % 2 == 1 && cnt1 + 1 >= cnt2) {
        printf("VICTORY");
    }
    else if(cnt1 % 2 == 0 && cnt1 >= cnt2) {
        printf("VICTORY");
    }
    else {
        printf("DEFEAT");
    }
}


/*
101010101

1이 홀수면 1
1이 짝수면 0
1이 없으면 0

결국 1의 개수가 늘진 않을듯?
시작히 홀수였다면 딱 한번 빼고

111
010110

010110
*/