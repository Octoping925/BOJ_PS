// https://www.acmicpc.net/problem/1929
#include <stdio.h>
#include <math.h>

int arr[1000010];

void initArr(int m)
{
    arr[1] = 1;
    for(int i = 2; i <= sqrt(m) + 1; ++i)
    {
        if(arr[i] == 0 && i < 1001) {
            for(int j = i * i; j <= m; j += i)
                arr[j] = 1;
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    initArr(m);

    for(int i = n; i <= m; ++i) {
        if(!arr[i])
            printf("%d\n", i);
    }
}