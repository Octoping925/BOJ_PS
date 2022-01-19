// https://www.acmicpc.net/problem/5102
#include <stdio.h>

int main()
{
    int n, k;
    while(1)
    {
        scanf("%d %d", &n, &k);
        if(n == 0 && k == 0) break;
        
        int real = n - k;
        
        if(real < 2) {
            printf("0 0\n");
        }
        else if(real % 2 == 0) {
            printf("%d 0\n", real / 2);
        }
        else {
            printf("%d 1\n", (real / 2) - 1);
        }
    }
}