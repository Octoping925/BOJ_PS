// https://www.acmicpc.net/problem/1769
#include <stdio.h>
#include <string.h>

char num[1000010];

int getSum(int x) {
    int res = 0;
    while(x > 9) {
        res += x % 10;
        x /= 10;
    }
    return res + x;
}

int main()
{
    scanf("%s", num);
    int len = strlen(num);

    if(len == 1) {
        printf("0\n%s", (num[0]-'0') % 3 == 0 ? "YES" : "NO");
        return 0;
    }

    int sum = 0;
    for(int i = 0; i < len; ++i) {
        sum += num[i] - '0';
    }

    int cnt = 1;
    while(sum > 9) {
        sum = getSum(sum);
        cnt++;
    }

    printf("%d\n%s", cnt, (sum-'0') % 3 == 0 ? "YES" : "NO");

}