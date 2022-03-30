// https://www.acmicpc.net/problem/10950
#include <stdio.h>
int main(){
    int n, x, y;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &x, &y);
        printf("%d\n", x+y);
    }
}