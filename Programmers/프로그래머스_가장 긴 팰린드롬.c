// https://programmers.co.kr/learn/courses/30/lessons/12904
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int min(int x, int y) {
    return x < y ? x : y;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    size_t len = strlen(s);
    
    char txt[5010];
    for(int i = 0 ; i < len; ++i) {
        txt[2*i] = '*';
        txt[2*i+1] = s[i];
    }
    txt[2*len] = '*';
    len = 2*len+1;
    
    int a[5010];
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
    
    return max;
}