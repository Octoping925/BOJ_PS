// https://www.acmicpc.net/problem/9095
#include <stdio.h>

int getSumCnt(int x)
{
    int answer[20]= {1, 1, 2, };
        
    for(int i = 3; i <= x; ++i)
        answer[i] += answer[i - 1] + answer[i - 2] + answer[i - 3];
    
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
        printf("%d\n", getSumCnt(m));
    }
    
    return 0;
}