// https://www.acmicpc.net/problem/24544
#include <stdio.h>

int arr[1010];

int main()
{
    int n;
    scanf("%d", &n);

    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum1 += arr[i];
    }
    
    for(int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        if(k == 0) sum2 += arr[i];
    }
    printf("%d\n%d", sum1, sum2);
}