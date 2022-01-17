// https://www.acmicpc.net/problem/4673
#include <stdio.h>

int arr[10001];

int getSum(int x)
{
    if(x < 10) return x;
    
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    for(int i = 1; i <= 10000; ++i)
    {
        if(arr[getSum(i) + i] == 0) {
            arr[getSum(i) + i] = 1;
        }
    }

    for(int i = 1; i <= 10000; ++i) {
        if(arr[i] == 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}
