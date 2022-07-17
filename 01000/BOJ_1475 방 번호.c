// https://www.acmicpc.net/problem/1475
#include <stdio.h>

int arr[9];
int n;

int main()
{
    scanf("%d", &n);

    while(n > 0) {
        int k = n % 10;
        if(k == 9) arr[6]++;
        else arr[k]++;
        n /= 10;
    }

    arr[6] = (arr[6] + 1) / 2;

    int max = 0;
    for(int i = 0; i <= 8; ++i) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    printf("%d", max);
    return 0;
}