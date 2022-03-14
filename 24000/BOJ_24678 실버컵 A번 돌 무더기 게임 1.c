// https://www.acmicpc.net/problem/24678
#include <stdio.h>
int n, arr[3], sum;
int main() {
    scanf("%d", &n);
    while(n--) {
        sum = 0;
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        for(int i = 0; i < 3; ++i) if(arr[i] % 2) sum++;
        if(sum < 2) printf("R\n");
        else printf("B\n");
    }
}