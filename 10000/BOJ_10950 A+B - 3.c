// https://www.acmicpc.net/problem/10950
#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int x, y;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        printf("%d\n", x+y);
    }
}