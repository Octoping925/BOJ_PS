// https://www.acmicpc.net/problem/2581
#include <stdio.h>

int arr[10010] = {1, 1};

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    for(int i = 2; i <= n; ++i)
    {
        if(arr[i] == 0) {
            for(int j = i + i; j <= n; j += i)
                arr[j] = 1;
        }
    }

    int min = 0;
    int sum = 0;
    for(int i = m; i <= n; ++i){
        if(arr[i] == 0) {
            if(min == 0) min = i;
            sum += i;
        }
    }
    
    if(min == 0) printf("-1");
    else printf("%d\n%d", sum, min);
}