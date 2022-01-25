// https://www.acmicpc.net/problem/2884
#include <stdio.h>

int main()
{
    int hh, mm;
    scanf("%d %d", &hh, &mm);
    
    if (mm >= 45) printf("%d %d", hh, mm - 45);
    else {
        mm = mm + 15;
        
        if (hh > 0) printf("%d %d", hh - 1, mm);
        else printf("23 %d", mm);
    }
}