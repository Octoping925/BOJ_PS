// https://programmers.co.kr/learn/courses/30/lessons/12977
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool erathos[3010];

void makeErathos() {
    for(int i = 2; i <= 3000; ++i) {
        if(!erathos[i]) {
            for(int j = i + i; j <= 3000; j += i) {
                erathos[j] = true;
            }
        }
    }
}

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    makeErathos();
    int answer = 0;

    for(int i = 0; i < nums_len; ++i) {
        for(int j = i+1; j < nums_len; ++j) {
            for(int k = j+1; k < nums_len; ++k) {
                if(!erathos[nums[i] + nums[j] + nums[k]]) {
                    ++answer;
                } 
            }
        }
    }
    return answer;
}