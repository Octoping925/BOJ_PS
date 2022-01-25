// https://www.acmicpc.net/problem/4344
#include <stdio.h>
int main()
{
    int c, k;
    scanf("%d", &c);
    
    for(int i = 0; i < c; ++i) {
        int n, sum = 0, arr[1010];
        scanf("%d", &n);
        
        for(int j = 0; j < n; ++j) {
            scanf("%d", &arr[j]);
            sum += arr[j];
        }
        
        float avg = (float)sum / n;
        int p = 0;
        
        for(int j = 0; j < n; ++j) {
            if(arr[j] > avg) p++;
        }
        printf("%0.3f%%\n", (float)p / n * 100);
    }
}