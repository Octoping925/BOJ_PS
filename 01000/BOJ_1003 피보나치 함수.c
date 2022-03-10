// https://www.acmicpc.net/problem/1003
#include <stdio.h>

int ans_z[45] = {1,0,1,1}, ans_o[45] = {0,1,1,2};
int n, k;

int main()
{
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &k);
        for(int j = 4; j <= k; ++j)
        {
            ans_z[j] = ans_z[j - 1] + ans_z[j - 2];
            ans_o[j] = ans_o[j - 1] + ans_o[j - 2];
        }
        
        printf("%d %d\n", ans_z[k], ans_o[k]);
    }
    
    return 0;
}