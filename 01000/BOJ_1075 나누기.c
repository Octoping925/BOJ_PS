// https://www.acmicpc.net/problem/1075
#include <stdio.h>

int main()
{
    int n, f;
    scanf("%d\n%d", &n, &f);

    int newN = n / 100 * 100;
    for(int i = 0; i < 100; ++i)
    {
        if((newN + i) % f == 0) {
            if(i < 10) printf("0");
            printf("%d", i);
            return 0;
        }
    }
}