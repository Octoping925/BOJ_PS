// https://www.acmicpc.net/problem/15921
#include <stdio.h>
int n, sum;
int arr[100];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    if(n == 0 || sum == 0) printf("divide by zero");
    else printf("1.00");

    return 0;
}