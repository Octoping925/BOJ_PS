// https://www.acmicpc.net/problem/5523
#include <stdio.h>

int n;
int a, b;
int score[2];

int main()
{
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &a, &b);
        if(a != b) {
            score[a - b > 0 ? 0 : 1]++;
        }
    }
    
    printf("%d %d", score[0], score[1]);
    return 0;
}