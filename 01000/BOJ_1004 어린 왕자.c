// https://www.acmicpc.net/problem/1004
#include <stdio.h>
#define pow(x) (x)*(x)

typedef struct point {
    int x;
    int y;
} Point;

int isIn(int x, int y, int r, Point k) {
    return pow(k.x - x) + pow(k.y - y) < pow(r);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        Point pr, des;
        scanf("%d %d", &pr.x, &pr.y);
        scanf("%d %d", &des.x, &des.y);

        int n, cnt = 0;
        scanf("%d", &n);

        while(n--) {
            int x, y, r;
            scanf("%d %d %d", &x, &y, &r);
            if(isIn(x, y, r, pr) ^ isIn(x, y, r, des)) cnt++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}