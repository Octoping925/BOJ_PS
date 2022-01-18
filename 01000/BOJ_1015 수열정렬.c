// https://www.acmicpc.net/problem/1015
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int *arr = malloc(sizeof(int) * (n + 1));
    
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    int min = 9999, tmp;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(min > arr[j]) {
                min = arr[j];
                tmp = j;
            }
        }
        arr[tmp] = 10000 + i;
        min = 9999, tmp = 0;
    }
    
        
    for(int i = 0; i < n; ++i) {
        printf("%d ", arr[i] - 10000);
    }
    
}