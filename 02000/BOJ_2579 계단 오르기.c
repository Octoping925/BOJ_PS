// https://www.acmicpc.net/problem/2579
#include <stdio.h>

int arr[310], chk[310];

int max(int a, int b) { return a > b ? a : b; }

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    
    
    if(n == 1) printf("%d", arr[1]);
    else if(n == 2) printf("%d", arr[1] + arr[2]);
    else
    {
        chk[0] = 0, chk[1] = arr[1], chk[2] = arr[2];
        
        for(int i = 3; i < n; ++i) {
            chk[i] = max(chk[i-2] + arr[i], chk[i-3] + arr[i] + arr[i-1]);
        }
        
        printf("%d", chk[n]);
    }
}

/*
for(int i=3;i<n;i++) { chk[i] = max(chk[i-2] + arr[i], chk[i-3] + arr[i] + arr[i-1]); }

*/