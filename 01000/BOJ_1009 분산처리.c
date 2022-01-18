// https://www.acmicpc.net/problem/1009
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i)
    {
        int a, b, c = 1;
        scanf("%d %d", &a, &b);
        
        for(int j = 0; j < b; ++j) {
            c = (c * a) % 10;
        }
        
        printf("%d\n", c == 0 ? 10 : c);
    }

    return 0;
}
