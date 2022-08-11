// https://www.acmicpc.net/problem/1977
#include <stdio.h>
#include <math.h>

int x, y;
int min, sum;

int isSquare(unsigned int num) {
    int x = sqrt(num) + 0.5;
    return x * x == num;
}

int main()
{
    scanf("%d %d", &x, &y);

    for(int i = x; i <= y; ++i) {
        if(isSquare(i)) {
            if(min == 0) min = i;
            sum += i;
        }
    }

    if(sum == 0) {
        printf("-1");
    }
    else {
        printf("%d\n%d", sum, min);
    }
    return 0;
}