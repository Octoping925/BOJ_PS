// https://www.acmicpc.net/problem/2839
#include <stdio.h>

int main()
{
    int answer[5010]= {0, };
    for(int i = 1; i < 5010; ++i)
        answer[i] = 5000;
    answer[3] = answer[5] = 1;
    
    int n;
    scanf("%d", &n);
    

    for(int i = 6; i <= n; ++i)
    {
        if(answer[i] > answer[i - 3] + 1)
            answer[i] = answer[i - 3] + 1;
            
        if(answer[i] > answer[i - 5] + 1)
            answer[i] = answer[i - 5] + 1;
    }
    
    printf("%d", answer[n] != 5000 ? answer[n] : -1);
    return 0;
}