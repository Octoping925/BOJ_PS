// https://www.acmicpc.net/problem/4880
#include <stdio.h>

int x, y, z;

int main()
{
    while(1) {
        scanf("%d %d %d", &x, &y, &z);

        if(x == 0 && y == 0 && z == 0) break;

        if(y - x == z - y) {
            printf("AP %d\n", z + y-x);
        }
        else {
            printf("GP %d\n", z * z/y);
        }
    }
    
    return 0;
}