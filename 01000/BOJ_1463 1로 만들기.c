// https://www.acmicpc.net/problem/1463
#include <stdio.h>

int n, a[1000010] = { 0, 0, 1, 1, 2 };

int min(int x, int y, int z)
{
	if (x < y)
	{
		if (x < z) return x;
		else return z;
	}
	else
	{
		if (y < z) return y;
		else return z;
	}
}

void make()
{
	int p1, p2, p3;

	for (int i = 5; i <= n; ++i)
	{
		if (i % 3 == 0) p1 = a[i / 3] + 1;
		else p1 = n;

		if (i % 2 == 0) p2 = a[i / 2] + 1;
		else p2 = n;

		p3 = a[i - 1] + 1;
		a[i] = min(p1, p2, p3);
	}
	return;
}

int main()
{
	scanf("%d", &n);
	make();
	printf("%d", a[n]);
	return 0;
}