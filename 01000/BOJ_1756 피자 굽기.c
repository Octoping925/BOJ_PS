// https://www.acmicpc.net/problem/1756
#include <stdio.h>

int oven[300010];
int d, n;

int main()
{
    scanf("%d %d", &d, &n);

    scanf("%d", &oven[d]);
    for(int i = d-1; i >= 1; i--) {
        scanf("%d", &oven[i]);
        if(oven[i+1] < oven[i]) 
            oven[i] = oven[i+1];
    }

    int depth = 0;
    while(n--) {
        int pizza;
        scanf("%d", &pizza);

        if(pizza > oven[d] || depth == d) {
            printf("0");
            return 0;
        }
        for(int i = depth + 1; i <= d; ++i) {
            if(pizza <= oven[i]) {
                depth = i;
                break;
            }
        }
    }

    printf("%d", d + 1 - depth);
    return 0;
}