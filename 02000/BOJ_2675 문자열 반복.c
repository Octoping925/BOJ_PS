// https://www.acmicpc.net/problem/2675
#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i)
    {
        int cnt;
        char line[1000];
        scanf("%d %s", &cnt, line);
        
        for(int j = 0; j < strlen(line); ++j)
        {
            for(int k = 0; k < cnt; ++k)
                printf("%c", line[j]);
        }
        printf("\n");
    }
}