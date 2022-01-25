// https://www.acmicpc.net/problem/8958
#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char line[100];
    
    scanf("%d\n", &n);
    
    for(int i = 0; i < n; ++i)
    {
        scanf("%s", line);
        int rensoku = 0, sum = 0;
        
        for(int j = 0; j < strlen(line); ++j)
        {
            if(line[j] == 'O')
            {
                ++rensoku;
                sum += rensoku;
            }
            else rensoku = 0;
        }
        
        printf("%d\n", sum);
    }
}