// https://www.acmicpc.net/problem/6763
#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d\n%d", &n, &m);

    if(m <= n)  printf("Congratulations, you are within the speed limit!");
    else if(m <= n + 20) printf("You are speeding and your fine is $100.");
    else if(m <= n + 30) printf("You are speeding and your fine is $270.");
    else  printf("You are speeding and your fine is $500.");
}