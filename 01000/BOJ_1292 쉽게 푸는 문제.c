// https://www.acmicpc.net/problem/1292
#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    int sum = 0;
    int num = 1, cnt = 1;
    for(int i = 1; i <= y; ++i) {
        if(cnt == 0) {
            cnt = ++num;
        }
        
        cnt--;
        
        if(i >= x) {
            sum += num;
        }
    }

    printf("%d", sum);
}