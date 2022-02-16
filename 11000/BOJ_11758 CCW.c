// https://www.acmicpc.net/problem/11758
#include <stdio.h>

int main()
{
    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d\n%d %d\n%d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    //x2-x1/y2-y1 == x3-x2/y3-y2
    if((x2 - x1) * (y3 - y2) == (x3 - x2) * (y2 - y1)) {
        printf("0");
        return 0;
    }

    if(x1 == x2) { // 12 or 6
        if(y2 > y1) { // 12
            if(x3 > x2) printf("-1");
            else printf("1");
        }
        else { // 6
            if(x3 > x2) printf("1");
            else printf("-1");
        }
    }
    else { // (y-y1)(x2-x1) == (y2-y1)(x-x1)

        if(x2 > x1) // 1~5
        {
            if((y3 - y1) * (x2 - x1) > (y2 - y1) * (x3 - x1)) printf("1");
            else printf("-1");
        }
        else // 7 ~ 11
        {
            if((y3 - y1) * (x2 - x1) > (y2 - y1) * (x3 - x1)) printf("1");
            else printf("-1");
        }
    }
}