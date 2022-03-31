// https://www.acmicpc.net/problem/2565
#include <stdio.h>

typedef struct point {
    int key;
    int val;
} Point;

int main()
{
    int n;
    scanf("%d", &n);

    Point arr[100];
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &arr[i].key, &arr[i].val);
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            if(arr[i].key > arr[j].key) {
                Point tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    
    int dp[100];
    for(int i = 0; i < n; ++i) {
        dp[i] = 1;
        for(int j = 0; j < i; ++j) {
            if(arr[j].val < arr[i].val && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }

    int max = 0;
    for(int i = 0; i < n; ++i)
        if(dp[i] > max) max = dp[i];
    printf("%d", n - max);
}