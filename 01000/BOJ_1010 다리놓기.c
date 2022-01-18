// https://www.acmicpc.net/problem/1010
#include <stdio.h>

int combination(int x, int y)
{
    int up[31], down[31];
    for(int i = 0; i < 31; ++i) up[i] = down[i] = 1;
    
    for(int i = 1; i <= y - x; ++i)
        up[i + x] = i + x, down[i] = i;
    
    
    for(int i = 1; i <= x; ++i)
    {
        for(int j = x + 1; j < 31; ++j)
        {
            int insu[6] = { 2, 3, 5, 7, 11, 13 };
            
            for(int k = 0; k < 6; ++k)
            {
                if(up[j] % insu[k] == 0 && down[i] % insu[k] == 0) {
                    up[j] /= insu[k];
                    down[i] /= insu[k];
                }
            }
        }
    }
    
    long long a = 1, b = 1;
    for(int i = 1; i < 31; ++i)
    {
        b *= up[i];
        a *= down[i];
    }

    return b / a;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        
        if(y - x > x) x = y - x;
        
        printf("%d\n", combination(x, y));
    }
}