// https://www.acmicpc.net/problem/4948
#include <stdio.h>

int arr[246915] = {1, 1};

int main()
{
    // 에라토노테네스의 체 제작
    for(int i = 2; i <= 246915; ++i)
    {
        if(arr[i] == 0) {
            for(int j = i + i; j <= 246915; j += i)
                arr[j] = 1;
        }
    }

    // Solve
    int n;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        
        int cnt = 0;
        for(int i = n + 1; i <= 2 * n; ++i)
            if(arr[i] == 0) ++cnt;
        printf("%d\n", cnt);
    }

    return 0;
}