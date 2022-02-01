// https://www.acmicpc.net/problem/14889
#include <stdio.h>
int n;
long long min = 223372036854775807;
int arr[22][22];
int teams[22];

int abs(int x) { return x > 0 ? x : -x; }

void recursive(int t1, int t2)
{
    if(t1 == n/2) {
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
        long long result = abs(t1Stat - t2Stat);
        if(result < min) min = result;
        return;
    }
    
    teams[t1 + t2 + 1] = 1;
    recursive(t1 + 1, t2);
    teams[t1 + t2 + 1] = 0;
    if(t2 < n/2) recursive(t1, t2 + 1);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            scanf("%d", &arr[i][j]);
    
    recursive(0, 0);
    printf("%lld", min);
}