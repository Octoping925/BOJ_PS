// https://www.acmicpc.net/problem/1356
#include <stdio.h>
#include <string.h>

char n[11];

int getNum(int idx) {
    return n[idx] - '0';
}

int getMultiply(int start, int end) {
    int res = 1;
    for(int i = start; i < end; ++i) {
         res *= getNum(i);
    }
    return res;
}

int main()
{
    scanf("%s", n);
    int len = strlen(n);

    int isFind = 0;
    for(int i = 1; i < len; ++i) {
        int front = getMultiply(0, i);
        int back = getMultiply(i, len);

        if(front == back) {
            isFind = 1;
            break;
        }
    }

    printf("%s", isFind ? "YES" : "NO");
    return 0;
}