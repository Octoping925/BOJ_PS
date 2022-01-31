// https://www.acmicpc.net/problem/2869
#include <stdio.h>

int main()
{
    int a, b, v, answer;
    scanf("%d %d %d", &a, &b, &v);
    
    if((v - a) % (a - b) == 0) answer = (v - a) / (a - b) + 1;
    else answer = (v - a) / (a - b) + 2;
    
    printf("%d", answer);
}