// https://www.acmicpc.net/problem/11653
#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int min = 3;
    while(N > 1) {
        if(N % 2 == 0) {
            printf("2\n");
            N /= 2;
        }
        else {
            for(int i = min; i <= N; i += 2)
            {
                if(N % i == 0) {
                    printf("%d\n", i);
                    N /= i;
                    break;
                }
            }
        }
    }
}