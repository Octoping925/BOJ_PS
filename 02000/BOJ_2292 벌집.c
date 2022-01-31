// https://www.acmicpc.net/problem/2292
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int i = -1;
    int cnt = 1;
    while(1)
    {
        cnt += 6 + 6 * i;
        if(n <= cnt) {
            printf("%d", i+2);
            return 0;
        }
        i++;
    }
}

/*

2~7    = 1 [6]
8~19   = 2 [12]
20~37  = 3 [18]
38~61  = 4 [24]

둘레 = 꼭짓점 6 + 6 * 단계 n

*/