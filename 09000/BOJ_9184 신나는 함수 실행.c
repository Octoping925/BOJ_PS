// https://www.acmicpc.net/problem/9184
#include <stdio.h>

int ans[30][30][30];
int sw[30][30][30];


int func(int a, int b, int c)
{
    int answer;
    
    if(sw[a][b][c]) return ans[a][b][c];
    
    else if(a < b && b < c) {
        answer = func(a, b, c-1) + func(a, b-1, c-1) - func(a, b-1, c);
        ans[a][b][c] = answer;
        sw[a][b][c]++;
    }
    
    else {
        answer = func(a-1, b, c) + func(a-1, b-1, c) + func(a-1, b, c-1) - func(a-1, b-1, c-1);
        ans[a][b][c] = answer;
        sw[a][b][c]++;
    }
    
    return answer;
}

int main()
{
    int a, b, c;
    
    for(int i = 0; i <= 20; ++i)
        for(int j = 0; j <= 20; ++j)
            for(int k = 0; k <= 20; ++k)
                if(i == 0 || j == 0 || k == 0)
                    ans[i][j][k] = 1, sw[i][j][k] = 1;

    
    for(int i = 1; i <= 20; ++i)
        for(int j = 1; j <= 20; ++j)
            for(int k = 1; k <= 20; ++k)
                ans[i][j][k] = func(i, j, k);


    while(1)
    {
        int res;
        scanf("%d %d %d", &a, &b, &c);
        
        if(a == -1 && b == -1 && c == -1) break;
        
        if(a <= 0 || b <= 0 || c <= 0) res = 1;
        else if(a > 20 || b > 20 || c > 20) res = ans[20][20][20];
        else res = ans[a][b][c];
        
        
        printf("w(%d, %d, %d) = %d\n", a, b, c, res);
    }
    
    return 0;
}