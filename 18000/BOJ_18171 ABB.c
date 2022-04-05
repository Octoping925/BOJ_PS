// https://www.acmicpc.net/problem/18171
#include <stdio.h>
#include <string.h>

char txt[2000010];
int a[2000010];
size_t len;

int min(int x, int y) {
    return x < y ? x : y;
}

int main() {
    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; ++i) {
        txt[2 * i] = '*';
        scanf("%c", &txt[2 * i + 1]);
    }
    txt[2 * n] = '*';

    len = 2 * n + 1;

    int r = 0; // 팰린드롬 최대 idx
    int p = 0; // 팰린드롬 중심
    for (int i = 0; i < len; ++i) {
        if (i <= r) {
            a[i] = min(a[2 * p - i], r - i);
        } else {
            a[i] = 0;
        }

        while (i - a[i] > 0 && i + a[i] < len && txt[i - a[i] - 1] == txt[i + a[i] + 1]) {
            ++a[i];
        }

        if (r < i + a[i]) {
            r = i + a[i];
            p = i;
        }
    }
    
    int center = n;
    int answer = 0;
    while(a[center] != n-answer) {
        answer++;
        center++;
    }

    printf("%d", answer);
}

/*
abb

*a*b*b*?*
0101310

*r*e*c*e*a*k*j*e*n*e*c*e*p*
010103010101010103010301010



len+2 한 녀석의 center의 A[center] 확인.

(a[center]-1)/2 = 거리.

center + (a[center]-1)/2 + answer


정답은 answer/2
*/