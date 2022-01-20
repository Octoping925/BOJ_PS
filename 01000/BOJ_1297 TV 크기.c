// https://www.acmicpc.net/problem/1297
#include <stdio.h>
#include <math.h>

int main()
{
    int d, h, w;
    scanf("%d %d %d", &d, &h, &w);

    double k = sqrt((h*h + w*w));
    printf("%d %d", (int)(d *h / k), (int)(d*w/k));
    return 0;
}