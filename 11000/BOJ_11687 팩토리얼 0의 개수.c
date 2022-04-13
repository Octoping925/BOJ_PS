// https://www.acmicpc.net/problem/11687
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int answer = 0;
    for(int i = 5; i <= 5*n; i += 5) {
        int tmp = i;
        while(tmp % 5 == 0) {
            answer++;
            tmp /= 5;
        }

        if(answer == n) {
            printf("%d", i);
            break;
        }
        else if(answer > n) {
            printf("-1");
            break;
        }
    }
}