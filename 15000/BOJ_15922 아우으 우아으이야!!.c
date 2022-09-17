// https://www.acmicpc.net/problem/15922
#include <stdio.h>

int max(int x, int y) { return x > y ? x : y; }

int main()
{
    int n;
    scanf("%d", &n);

    int left = 0, right = 0;
    int sum = 0;

    for(int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        if(i == 0) {
            left = a;
            right = b;
        }
        else {
            if(a > right) {
                sum += right - left;
                left = a;
                right = b;
            }
            else {
                right = max(b, right);
            }
        }
    }

    printf("%d", sum + right - left);
    return 0;
}