// https://www.acmicpc.net/problem/1874
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int* stack = malloc(sizeof(int) * (n + 10));
    char* arr = malloc(sizeof(char) * (2 * n + 10));

    int stlen = 0;
    int arrlen = 0;
    int now = 1;

    for(int i = 0; i < n; ++i)
    {
        int k;
        scanf("%d", &k);

        if(stlen == 0 || k > stack[stlen - 1])
        {
            for(; now <= k; ++now)
            {
                stack[stlen++] = now;
                arr[arrlen++] = '+';
            }
            
        }
        else if(k < stack[stlen - 1])
        {
            printf("NO");
            return 0;
        }

        arr[arrlen++] = '-';
        stlen--;
    }

    for(int i = 0; i < arrlen; ++i)
        printf("%c\n", arr[i]);
    
    return 0;
}