// https://www.acmicpc.net/problem/14889
#include <stdio.h>
int n, min = 2100000000;
int arr[22][22];
int teams[22];

int abs(int x) { return x > 0 ? x : -x; }

void recursive(int depth, int cnt)
{
    if(cnt == n/2 || depth - cnt == n/2) {
        int t1Stat = 0, t2Stat = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(teams[i] == 1)
            {
                for(int j = 1; j <= n; ++j)
                    if(teams[j] == 1)
                        t1Stat += arr[i][j];
            }
            else
            {
                for(int j = 1; j <= n; ++j)
                    if(teams[j] == 0)
                        t2Stat += arr[i][j];
            }
        }
        int result = abs(t1Stat - t2Stat);
        if(result < min) min = result;

        return;
    }
    
    teams[depth + 1] = 1;
    recursive(depth + 1, cnt+1);
    teams[depth + 1] = 0;
    recursive(depth + 1, cnt);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            scanf("%d", &arr[i][j]);
    
    recursive(0, 0);
    printf("%d", min);
}