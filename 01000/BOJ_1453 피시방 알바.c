// https://www.acmicpc.net/problem/1453
#include <stdio.h>

int n, ans;
int arr[101];

int main() {
    scanf("%d", &n);
    while(n--) {
        int k;
        scanf("%d", &k);
        if(arr[k]++) {
            ans++;
        }
    }
    printf("%d", ans);
}