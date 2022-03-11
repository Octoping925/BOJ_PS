// https://www.acmicpc.net/problem/13755
// #include <stdio.h>

typedef struct square {
    int w, h;
} Square;

int solution()
{
    Square x1, x2, x3;
    scanf("%d %d", &x1.w, &x1.h);
    scanf("%d %d", &x2.w, &x2.h);
    scanf("%d %d", &x3.w, &x3.h);

    if(x1.w == x2.w && x2.w == x3.w) {
        if(x1.h + x2.h + x3.h == x1.h) {
            return 1;
        }
    }
    if(x1.h == x2.h && x2.h == x3.h) {
        if(x1.w + x2.w + x3.w == x1.w) {
            return 1;
        }
    }

    if(x1.h == x2.h) {
        if(x1.h + x2.h == x3.h)
    }
}

int main()
{
    printf("%d", solution());
}
