// https://www.acmicpc.net/problem/25191
#include <stdio.h>
int min(int x, int y) {
    return x < y?  x : y;
}
int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    printf("%d", min(x, y/2 + z));
    return 0;
}