// https://www.acmicpc.net/problem/14490
#include <stdio.h>

int d, u;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main()
{
    scanf("%d:%d", &d, &u);
    int gcdVal = gcd(d, u);
    printf("%d:%d", d / gcdVal, u / gcdVal);
}