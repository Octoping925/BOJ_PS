// https://www.acmicpc.net/problem/1546
#include <stdio.h>

int main() {
	int n;
	int arr[1010];
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);

	int max = -1;
	for(int i = 0; i < n; ++i) if(arr[i] > max) max = arr[i];

	float sum = 0;
	for(int i = 0; i < n; ++i) sum += (float)arr[i] / max * 100;
	printf("%f", sum / n);
    return 0;
}
  