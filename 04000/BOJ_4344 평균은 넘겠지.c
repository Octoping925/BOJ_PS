// https://www.acmicpc.net/problem/4344
#include <stdio.h>
int main()
{
    int c, k;
    scanf("%d", &c);
    
    while(c--) {
        int n, sum = 0, arr[1010];
        scanf("%d", &n);
        
        for(int j = 0; j < n; ++j) {
            scanf("%d", &arr[j]);
            sum += arr[j];
        }
        
        double avg = (double)sum / n;
        int p = 0;
        
        for(int j = 0; j < n; ++j) {
            if(arr[j] > avg) p++;
        }
        printf("%0.3lf%%\n", (double)p / n * 100);
    }
}