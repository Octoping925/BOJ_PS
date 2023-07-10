// https://www.acmicpc.net/problem/9506
#include <stdio.h>

int arr[50000];

int main() {
    do {
        int n;
        scanf("%d", &n);
        if(n == -1) {
            break;
        }

        int cnt = 0;
        int sum = 0;
        for(int i = 1; i < n; ++i) {
            if(n % i == 0) {
                arr[cnt++] = i;
                sum += i;
            }
        }

        if(sum == n) {
            printf("%d = ", n);
            for(int i = 0; i < cnt; ++i) {
                printf("%d", arr[i]);
                if(i != cnt - 1) {
                    printf(" + ");
                }
            }
            printf("\n");
        }
        else {
            printf("%d is NOT perfect.\n", n);
        }
    } while (1);
}
