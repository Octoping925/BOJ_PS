// https://www.acmicpc.net/problem/1100
#include <stdio.h>

int sum;

int main()
{
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            char c;
            scanf(" %c", &c);
            if(c == 'F' && (i+j) % 2 == 0) ++sum;
        }
    }
    printf("%d", sum);
}