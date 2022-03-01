// https://www.acmicpc.net/problem/6975
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int k;
        scanf("%d", &k);

        int sum = 0;
        for(int j = 1; j < k; ++j)
        {
            if(k % j == 0) 
                sum += j;
        }
        if(sum < k) printf("%d is a deficient number.\n", k);
        else if(sum == k) printf("%d is a perfect number.\n", k);
        else printf("%d is an abundant number.\n", k);
        printf("\n");
    }
}