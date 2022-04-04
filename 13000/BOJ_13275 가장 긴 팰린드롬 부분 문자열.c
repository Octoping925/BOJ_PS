// https://www.acmicpc.net/problem/13275
#include <stdio.h>
#include <string.h>

char tmp[100010];
char txt[200020];
int a[200020];

int min(int x, int y) {
    return x < y ? x : y;
}

int main()
{
    scanf("%s", tmp);
    size_t len = strlen(tmp);

    // 매내처는 홀수길이만 판별 가능하므로, *을 넣어주어 홀수길이 만들어주기
    for(int i = 0; i < len; ++i) {
        txt[2*i] = '*';
        txt[2*i+1] = tmp[i];
    }
    txt[2*len] = '*';
    len = 2 * len + 1;

    int r = 0;
    int p = 0;
    for(int i = 0; i < len; ++i) {
        if(i <= r) { // 어떤 팰린드롬 안에 속해있으면
            a[i] = min(a[2*p-i], r-i);
        }
        else {
            a[i] = 0;
        }

        while(i+a[i] > 0 && i+a[i] < len-1 && txt[i - a[i] - 1] == txt[i + a[i] + 1]) {
            a[i]++;
        }

        if(r < i + a[i]) { // 팰린드롬 안에 속해있지 않으면
            r = i + a[i];
            p = i;
        }
    }

    int max = 0;
    for(int i = 0; i < len; ++i) {
        if(a[i] > max) max = a[i];
    }

    printf("%d", max);
    return 0;
}