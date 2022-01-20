// https://www.acmicpc.net/problem/1978
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    int* arr = malloc(sizeof(int) * n);

    int max = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if(arr[i] > max) max = arr[i];
    }

    int* ch = malloc(sizeof(int) * (max + 5));
    memset(ch, 0, sizeof(int) * (max + 5));
    ch[1] = 1;

    for(int i = 2; i <= max; ++i)
    {
        if(ch[i] == 0) {
            for(int j = i * i; j <= max; j += i)
                ++ch[j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; ++i)
        if(ch[arr[i]] == 0)
            ++cnt;

    printf("%d", cnt);
}