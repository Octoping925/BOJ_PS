#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    long long p = n;
    int len = 0;
    while(p > 0) {
        p/=10;
        len++;
    }
    
    int cnt = 0;
    int* answer = (int*)malloc(len * sizeof(int));

    while(n > 0) {
        answer[cnt++] = n % 10;
        n /= 10;
    }
    
    return answer;
}