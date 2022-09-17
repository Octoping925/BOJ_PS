// https://www.acmicpc.net/problem/15922
#include <stdio.h>

int left = -1e9, right = -1e9;
int sum = 0;

int max(int x, int y) { return x > y ? x : y; }

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);

        if(x > right) {
            sum += right - left;
            left = x;
            right = y;
        }
        else {
            right = max(y, right);
        }
    }

    printf("%d", sum + right - left);
}