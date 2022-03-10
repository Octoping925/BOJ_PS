// https://www.acmicpc.net/problem/10250
#include <stdio.h>

void printAddZero(int x) { 
    if(x < 9) printf("0");
    printf("%d\n", x+1);
}

int main()
{
    int T, H, W, N;
    scanf("%d", &T);

    while(T--)
    {
        scanf("%d %d %d", &H, &W, &N);
        printf("%d", N % H == 0 ? H : N % H);
        printAddZero((N-1) / H);
    }
}