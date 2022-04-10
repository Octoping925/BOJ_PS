// https://www.acmicpc.net/problem/11054
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[1001];
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    int dp1[1001];
    for(int i = 0; i < n; ++i) {
        dp1[i] = 1;
        for(int j = 0; j < i; ++j) {
            if(arr[j] < arr[i] && dp1[j] + 1 > dp1[i])
                dp1[i] = dp1[j] + 1;
        }
    }

    int dp2[1001];
    for(int i = n-1; i >= 0; --i) {
        dp2[i] = 1;
        for(int j = n-1; j > i; --j) {
            if(arr[j] < arr[i] && dp2[j] + 1 > dp2[i])
                dp2[i] = dp2[j] + 1;
        }
    }
    
    int max = 0;
    for(int i = 0; i < n; ++i)
        if(dp1[i] + dp2[i] - 1 > max) max = dp1[i] + dp2[i] - 1;
    printf("%d", max);
}

/*

10
1 5 2 1 4 3 4 5 2 1

1 2 2 1 3 3 4 5 2 1
1 5 2 1 4 3 3 3 2 1

*/