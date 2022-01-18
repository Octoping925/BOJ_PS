// https://www.acmicpc.net/problem/1037
#include <stdio.h>
#include <algorithm>

int main()
{
    int n;
    int a[55];
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
        
    std::sort(a, a + n);
    
    printf("%d", a[0] * a[n - 1]);
}