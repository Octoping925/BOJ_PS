// https://www.acmicpc.net/problem/24498
#include <stdio.h>

int arr[1000010];

int min(int x, int y) { return x < y ? x : y; }

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    int max = 0;
    for(int i = 1; i < n - 1; ++i)
    {
        int k = arr[i] + min(arr[i - 1], arr[i + 1]);
        if(k > max) max = k;
    }
    
    if(arr[0] > max) max = arr[0];
    if(arr[n - 1] > max) max = arr[n - 1];

    printf("%d", max);
}