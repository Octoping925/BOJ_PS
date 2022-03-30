// https://www.acmicpc.net/problem/17608
#include <stdio.h>

int arr[100000];
int main()
{
    int n;
    scanf("%d", &n);

    int max = 0, idx = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if(arr[i] > max) max = arr[i];
    }

    int stack = 0, answer = 0;
    for(int i = n-1; i >= 0; --i) {
        if(arr[i] > stack) 
            stack = arr[i], answer++;
    }

    printf("%d", answer);
}