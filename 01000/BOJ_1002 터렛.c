// https://www.acmicpc.net/problem/1002
#include <stdio.h>

int n, x1, y1, r1, x2, y2, r2, distance;

int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) {
                if(!r1) printf("1");
                else printf("-1");
            }
            if (r1 != r2) printf("0");
        }
        else {
            distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            if ((r1 + r2) * (r1 + r2) == distance) printf("1");
            else if ((r1 + r2) * (r1 + r2) < distance) printf("0");
            else if ((r1 - r2) * (r1 - r2) == distance) printf("1");
            else if ((r1 - r2) * (r1 - r2) > distance) printf("0");
            else if ((r1 + r2) * (r1 + r2) > distance) printf("2");
        }
        printf("\n");
    }
}
