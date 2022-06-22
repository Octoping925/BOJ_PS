// https://programmers.co.kr/learn/courses/30/lessons/77484
#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) {
    return x < y ? x : y;
}

int cnt[46];
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    for(int i = 0; i < 6; ++i) {
        cnt[win_nums[i]]++;
    }

    int zeroCnt = 0;
    int matchCnt = 0;
    for(int i = 0; i < lottos_len; ++i) {
        if(!lottos[i]) zeroCnt++;
        else if(cnt[lottos[i]]) {
            matchCnt++;
        }
    }

    int* answer = (int*)malloc(1);
    answer[0] = min(7 - matchCnt - zeroCnt, 6);
    answer[1] = min(7 - matchCnt, 6);
    return answer;
}