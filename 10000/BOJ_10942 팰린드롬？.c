// https://www.acmicpc.net/problem/10942
#include <stdio.h>

int arr[4010];
int a[4010];

int min(int x, int y) {
    return x < y ? x : y;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i) {
        arr[2*i-1] = -1;
        scanf("%d", &arr[2*i]);
    }
    arr[2*n+1] = -1;

    size_t len = 2 * n + 1;
    int r = 0;
    int p = 0;
    for(int i = 1; i <= len; ++i) {
        if(i <= r) { // 어떤 팰린드롬 안에 속해있으면
            a[i] = min(a[2*p-i], r-i);
        }
        else {
            a[i] = 0;
        }

        while(i+a[i] > 1 && i+a[i] < len && arr[i - a[i] - 1] == arr[i + a[i] + 1]) {
            a[i]++;
        }

        if(r < i + a[i]) { // 팰린드롬 안에 속해있지 않으면
            r = i + a[i];
            p = i;
        }
    }

    int k;
    scanf("%d", &k);
    while(k--) {
        int x, y;
        scanf("%d %d", &x, &y);
        int dis = y - x;
        x *= 2;
        y *= 2;
        
        if(a[(x + y) / 2] > dis) printf("1\n");
        else printf("0\n");
    }

    return 0;
}