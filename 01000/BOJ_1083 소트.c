// https://www.acmicpc.net/problem/1083
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int arr = malloc(sizeof(int)*n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    int s;
    scanf("%d", &s);

    int cnt = 0;
    for(int i = 0; i < n-1; ++i) {
        for(int j = 0; j < n-1; ++j) {
            if(arr[j] < arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                ++cnt;
            }
        }
    }

    for(int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}