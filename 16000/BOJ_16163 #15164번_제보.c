// https://www.acmicpc.net/problem/16163
#include <stdio.h>
#include <string.h>

char txt[4000010];
char tmp[2000010];
int a[4000010];
size_t len;

int min(int x, int y) {
    return x < y ? x : y;
}

int main()
{
    scanf("%s", tmp);
    len = strlen(tmp);

    for(int i = 0 ; i < len; ++i) {
        txt[2*i] = '*';
        txt[2*i+1] = tmp[i];
    }
    txt[2*len] = '*';
    len = 2*len+1;

    int r = 0; // 팰린드롬 최대 idx
    int p = 0; // 팰린드롬 중심
    for(int i = 0; i < len; ++i) {
        if(i <= r) {
            a[i] = min(a[2*p-i], r-i);
        }
        else {
            a[i] = 0;
        }

        while(i-a[i] > 0 && i+a[i] < len && txt[i-a[i]-1] == txt[i+a[i]+1]) {
            ++a[i];
        }

        if(r < i + a[i]) {
            r = i + a[i];
            p = i;
        }
    }

    long long cnt = 0;
    for(int i = 0; i < len; ++i) {
        cnt += (a[i]+1)/2;
    }

    printf("%lld", cnt);
}