// https://www.acmicpc.net/problem/1026
#include <stdio.h>
#include <algorithm>

int main()
{
    int n;
    int a[55], b[55];
    scanf("%d", &n);
    
    
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
        
    for(int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
        
    std::sort(a, a + n);
    std::sort(b, b + n);
    
    int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += a[i] * b[n - 1 - i];
        
    printf("%d", sum);
}