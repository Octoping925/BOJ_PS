// https://www.acmicpc.net/problem/1004
#include <stdio.h>

typedef struct point {
    int x;
    int y;
} Point;

int pow(int x) { return x * x; }

int isIn(int x, int y, int r, Point k)
{
    return pow(k.x - x) + pow(k.y - y) < pow(r) ? 1 : -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; ++testcase)
    {
        Point pr, des;
        scanf("%d %d", &pr.x, &pr.y);
        scanf("%d %d", &des.x, &des.y);

        int n, cnt = 0;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i)
        {
            int x, y, r;
            scanf("%d %d %d", &x, &y, &r);
            if(isIn(x, y, r, pr) * isIn(x, y, r, des) == -1) cnt++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}