//https://www.acmicpc.net/problem/2693
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i)
    {
        int arr[11];
        for(int j = 0; j < 10; ++j)
            scanf("%d", &arr[j]);
        
        int max = -1, sec = -1, thd = -1;
        
        for(int j = 0; j < 10; ++j)
        {
            if(arr[j] > max)
            {
                thd = sec;
                sec = max;
                max = arr[j];
            }
            else if(arr[j] > sec)
            {
                thd = sec;
                sec = arr[j];
            }
            else if(arr[j] > thd)
            {
                thd = arr[j];
            }
        }
        
        printf("%d\n", thd);
    }
    
    return 0;
}