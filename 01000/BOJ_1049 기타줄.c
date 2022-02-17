// https://www.acmicpc.net/problem/1049
#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int packageMin = 1001, natMin = 1001;
    for(int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if(x < packageMin) packageMin = x;
        if(y < natMin) natMin = y;
        if(natMin * 6 < packageMin) packageMin = natMin * 6;
    }
    int price = packageMin * (n / 6);
    if((n % 6) * natMin < packageMin) price += (n % 6) * natMin;
    else price += packageMin;

    printf("%d", price);
}
