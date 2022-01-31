// https://www.acmicpc.net/problem/1193
#include <stdio.h>

int main()
{
    int X;
    scanf("%d", &X);

    for(int i = 1; i <= X; ++i)
    {
        if(X <= i*(i+1)/2)
        {
            int cnt = X - (i-1)*i/2;
            if(i % 2) printf("%d/%d", i+1-cnt, cnt);
            else printf("%d/%d", cnt, i+1-cnt);
            return 0;
        }
    }
}