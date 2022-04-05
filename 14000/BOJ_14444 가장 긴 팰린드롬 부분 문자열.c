// https://www.acmicpc.net/problem/14444
#include <stdio.h>
#include <string.h>

char txt[200010];
char tmp[100010];
int a[200010];
size_t len;

int min(int x, int y) {
    return x < y ? x : y;
}

int main()
{
    scanf("%s", &tmp);
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

    int max = 0;
    for(int i = 0; i < len; ++i) {
        if(a[i] > max) max = a[i];
    }

    printf("%d", max);
}