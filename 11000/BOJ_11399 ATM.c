// https://www.acmicpc.net/problem/11399
#include <stdio.h>

int n, ans;
int arr[1010], sum[1010];

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 2; j <= n; ++j) {
            if(arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + arr[i];
        ans += sum[i];
    }
    
    printf("%d", ans);
}