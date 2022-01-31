// https://www.acmicpc.net/problem/10818
#include <stdio.h>

int n, a, max = -1000000, min = 1000000;

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);
		if (max < a) max = a;
		if (min > a) min = a;
	}
	printf("%d %d", min, max);
	return 0;
}