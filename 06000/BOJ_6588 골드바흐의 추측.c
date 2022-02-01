// https://www.acmicpc.net/problem/6588
#include <stdio.h>
#include <math.h>

int arr[1000010];

void initArr(int m)
{
    arr[1] = 1;
    for(int i = 2; i <= sqrt(m) + 1; ++i)
    {
        if(arr[i] == 0 && i < 10001) {
            for(int j = i * i; j <= m; j += i)
                arr[j] = 1;
        }
    }
}

int main()
{
    int n;

    initArr(1000000);

    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;

        int l = 2, r = n;
        while(1)
        {
            if(arr[l] == 1) ++l;
            if(arr[r] == 1) --r;

            if(arr[l] == 0 && arr[r] == 0)
            {
                int sum = l + r;
                if(sum == n) {
                    printf("%d = %d + %d\n", n, l, r);
                    break;
                }
                else if(sum > n) r--;
                else l++;
            }
        }
    }
}