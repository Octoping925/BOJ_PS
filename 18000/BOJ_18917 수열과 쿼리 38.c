// https://www.acmicpc.net/problem/18917
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	long long sum = 0;
	long long xxor = 0;
	
	while(n--) {
		int command;
		scanf("%d", &command);
		
		int k;
		switch(command) {
			case 1:
				scanf("%d", &k);
				sum += k;
				xxor ^= k;
				break;
				
			case 2:
				scanf("%d", &k);
				sum -= k;
				xxor ^= k;
				break;
				
			case 3:
				printf("%lld\n", sum);
				break;
				
			case 4:
				printf("%lld\n", xxor);
				break;
		}
	}
		return 0;
}
