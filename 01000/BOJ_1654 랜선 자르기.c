// https://www.acmicpc.net/problem/1654
#include <stdio.h>

int str[10010];


int cut(int x, int goal)
{
    int sum = 0;
    for(int i = 0; i < n; ++j)
    {
        sum += (str[i] / x);
        
        if(sum >= goal)
            return 1;
    }
    return 0;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int max = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &str[i]);
        if(str[i] > str[max]) max = i;
    }


    for(int i = str[max]; i >= 0; --i)
    {
        if(cut(i, k)) printf("%d", i);
        int sum = 0;
        for(int j = 0; j < n; ++j)
        {
            sum += (str[j] / i);
            
            if(sum >= k) {
                printf("%d", i);
                return 0;
            }
        }
        
    }
}


/*

max 부터 시작해서, 1씩 내려오면서 모든 선들을 나눔.
그 몫들의 합이 k를 넘으면 그게 최대.


min이면 다 자를 수 있음. k개 만들어야 하니,   최악의 경우 k/n

모두 min임. n개를 min/?만큼 자른게 모두 같음  min / ? * n >= k   min*n/k >= ?
12
100 100 100 100 100

500/12 >= ?
125/3 >= ?
81.x >= ?


아니면 max/k




5
15000
100
20
10

max / 5 = 3000
min / 5 = 2


11
800
740
450
530

max/11= 72
min/11 = 48


1003
10000
10
10
10

1011
10000
100
10
7

*/