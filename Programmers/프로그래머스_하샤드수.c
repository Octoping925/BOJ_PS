// https://programmers.co.kr/learn/courses/30/lessons/12947
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    int tmp = x, sum = 0;

    while (tmp > 9) {
        sum += tmp % 10;
        tmp /= 10;
    }

    sum += tmp;

    return x % sum == 0;
}