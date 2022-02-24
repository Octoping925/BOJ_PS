// https://www.acmicpc.net/problem/1043
#include <stdio.h>

int tree[55];
int party[55][55];
int people[55];
int memo[55];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        int tmp;
        scanf("%d", &tmp);
        tree[tmp] = 1;
    }

    for(int i = 0; i < m; ++i)
    {
        int sw = 0;
        scanf("%d", &people[i]);
        for(int j = 0; j < people[i]; ++j) {
            scanf("%d", &party[i][j]);
        }
    }

    int cnt = m;
    for(int i = 0; i < m; ++i)
    {
        if(memo[i] == 0)
        {
            for(int j = 0; j < people[i]; ++j)
            {
                if(tree[party[i][j]] == 1) {
                    memo[i] = 1;
                    cnt--;
                    
                    for(int k = 0; k < people[i]; ++k)
                        tree[party[i][k]] = 1;
                    
                    i = -1;
                    break;
                }
            }
        }
        
    }
    printf("%d", cnt);
}