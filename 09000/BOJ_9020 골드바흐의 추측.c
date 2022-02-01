// https://www.acmicpc.net/problem/9020
#include <stdio.h>
#include <math.h>

int arr[10010];

void initArr(int m)
{
    arr[1] = 1;
    for(int i = 2; i <= sqrt(m) + 1; ++i)
    {
        if(arr[i] == 0 && i < 1001) {
            for(int j = i * i; j <= m; j += i)
                arr[j] = 1;
        }
    }
}

int main()
{
    int T, n;
    scanf("%d", &T);

    initArr(10000);

    for(int t = 0; t < T; ++t)
    {
        scanf("%d", &n);
        int l = n / 2, r = n / 2;
        while(1)
        {
            if(arr[l] == 1) --l;
            if(arr[r] == 1) ++r;

            if(arr[l] == 0 && arr[r] == 0)
            {
                int sum = l + r;
                if(sum == n) {
                    printf("%d %d\n", l, r);
                    break;
                }
                else if(sum > n) l--;
                else r++;
            }
        }
    }
}