// https://www.acmicpc.net/problem/1526
#include <stdio.h>

int is47(int x) {
    while(x > 0) {
        if(x % 10 != 4 && x % 10 != 7) {
            return 0;
        }
        x /= 10;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    while(!is47(n)) {
        n--;
    }

    printf("%d", n);
}
