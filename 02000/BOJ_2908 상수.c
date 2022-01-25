// https://www.acmicpc.net/problem/2908
#include <stdio.h>

int sang(int x) {
	return x % 10 * 100 + x / 10 % 10 * 10 + x / 100;
}

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	x = sang(x);
	y = sang(y);
    printf("%d", x > y ? x : y);
    return 0;
}