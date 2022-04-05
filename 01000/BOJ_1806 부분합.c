// https://www.acmicpc.net/problem/1806
#include <stdio.h>

int arr[100010];
int n, s, chk;

int min(int x, int y) {
    return x < y ? x : y;
}

int main()
{
    scanf("%d %d", &n, &s);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        chk += arr[i];
    }
    if (chk < s) {
        printf("0");
        return 0;
    }

    int p1 = 1;
    int p2 = 1;
    int minLen = n;
    int sum = arr[1];

    while(p1 <= n) {
        if(sum < s) {
            if(p2 == n) {
                break;
            }
            p2++;
            sum += arr[p2];
        }
        else {
            minLen = min(minLen, p2 - p1 + 1);
            if(p1 == p2) {
                p2++;
                sum += arr[p2];
            }
            else {
                sum -= arr[p1];
                p1++;
            }
        }
    }

    printf("%d", minLen);
    return 0;
}