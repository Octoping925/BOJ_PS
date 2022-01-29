// https://www.acmicpc.net/problem/3040
#include <stdio.h>

int main()
{
    int arr[10], sum = 0;
    for(int i = 1; i < 10; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    for(int i = 1; i < 10; ++i)
    {
        for(int j = i + 1; j < 10; ++j)
        {
            if(sum - arr[i] - arr[j] == 100) {
                for(int k = 1; k < 10; ++k)
                    if(k != i && k != j)
                        printf("%d\n", arr[k]);
                return 0;
            }
        }
    }
}