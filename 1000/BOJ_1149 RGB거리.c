//https://www.acmicpc.net/problem/1149
#include <stdio.h>

int price[1010][4];
int answer[1010][4];

int main()
{
    int n;

    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; ++i)
        scanf("%d %d %d", &price[i][1], &price[i][2], &price[i][3]);
    
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= 3; ++j)
        {
            for(int k = 1; k <= 3; ++k)
            {
                if(j != k && (answer[i][j] == 0 || answer[i][j] > answer[i - 1][k] + price[i][j]))
                    answer[i][j] = answer[i - 1][k] + price[i][j];
            }
        }
    }
    
    int min = 2100000000;
        for(int j = 1; j <= 3; ++j)
        {
            if(min > answer[n][j]) min = answer[n][j];
        }
        printf("%d", min);
    
    return 0;
}
