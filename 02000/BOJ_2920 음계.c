// https://www.acmicpc.net/problem/2920
#include <stdio.h>

int main()
{
    int line[10];
    
    for(int i = 1; i <= 8; ++i)
        scanf("%d", &line[i]);
        
    if(line[1] == 1)
    {
        for(int i = 1; i <= 8; ++i)
        {
            if(line[i] != i) {
                printf("mixed");
                return 0;
            }
        }
        printf("ascending");
        return 0;
    }
    else if(line[1] == 8)
    {
        for(int i = 8; i >= 1; --i)
        {
            if(line[9 - i] != i) {
                printf("mixed");
                return 0;
            }
        }
        printf("descending");
        return 0;
    }
    printf("mixed");
}