// https://www.acmicpc.net/problem/1012
#include <stdio.h>

int bat[52][52];

void init()
{
    for(int i = 0; i < 51; ++i)
        for(int j = 0; j < 51; ++j)
            bat[i][j] =  0;
}

void exp(int x, int y)
{
    if(bat[x][y] == 0) return;
    else bat[x][y] = 0;
    
    
    if(x > 0) exp(x-1, y);
    if(x < 50) exp(x+1, y);
    if(y > 0) exp(x, y-1);
    if(y < 50) exp(x, y+1);
}


int main()
{
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        int w, h, n;
        scanf("%d %d %d", &w, &h, &n);
        
        // make map
        init();
        for(int i = 0; i < n; ++i)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            bat[x][y] = 1;
        }
        
        
        // explore map        
        int cnt = 0;
        
        for(int i = 0; i < w; ++i)
        {
            for(int j = 0; j < h; ++j)
            {
                if(bat[i][j])
                {
                    exp(i, j);
                    ++cnt;
                }
            }
        }
        
        printf("%d\n", cnt);
    }

    return 0;
}
