// https://www.acmicpc.net/problem/2775
#include <stdio.h>

int building[15][15];

int main()
{
    int T;
    scanf("%d", &T);
    for(int tc = 0; tc < T; ++tc)
    {
        int n, k;
        scanf("%d\n%d", &k, &n);

        for(int i = 1; i <= k; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {   
                building[i][j] = 0;
                for(int k = 1; k <= j; ++k)
                {
                    if(i == 1) building[i][j] += k;
                    else building[i][j] += building[i - 1][k];
                }
            }
        }
        
        // printf("--\n");
        // for(int i = k; i >= 1; --i){
        //     for(int j = 1; j <= n; ++j)
        //         printf("%d ", building[i][j]);
        //     printf("\n");
        // }
        // printf("--\n");
        printf("%d\n", building[k][n]);
    }
}