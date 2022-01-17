// https://www.acmicpc.net/problem/3460
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i)
    {
        int m;
        scanf("%d", &m);
        
        int cnt = 0;
        
        while(m > 1)
        {
            if(m % 2 == 1) printf("%d ", cnt);
            m /= 2;
            ++cnt;
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}