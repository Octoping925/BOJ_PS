// https://www.acmicpc.net/problem/11945
#include <stdio.h>

char arr[10];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0, j = 0; i < n; ++i) {
        for(; j < m; j++) {
            scanf(" %c", &arr[j]);
        }
        for(; j > 0; j--) {
            printf("%c", arr[j-1]);
        }
        printf("\n");
    }
    
    return 0;
}