// https://www.acmicpc.net/problem/15988
#include <stdio.h>

long long getSumCnt(int x)
{
    long long answer[1000010]= {1, 1, 2, };
        
    for(int i = 3; i <= x; ++i)
        answer[i] += (answer[i - 1] + answer[i - 2] + answer[i - 3]) % 1000000009;
    
    return answer[x];
}

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i)
    {
        int m;
        scanf("%d", &m);
        printf("%lld\n", getSumCnt(m));
    }
    
    return 0;
}