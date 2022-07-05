// https://www.acmicpc.net/problem/1205
#include <stdio.h>

int n, score, p;
int idx = 1, same;

int main()
{
    scanf("%d %d %d", &n, &score, &p);

    while(n--) {
        int k;
        scanf("%d", &k);

        if(k > score) idx++;
        else if(k == score) same++;
    }

    printf("%d", idx + same <= p ? idx : -1);
    return 0;
}