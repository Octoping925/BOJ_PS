// https://www.acmicpc.net/problem/14852
#include <stdio.h>

long dp[1000001] = {1, 2, 7, };
long fp[1000001];

long func(int n){
    if(n==2) return 1;
    if(fp[n] != 0) return fp[n];
    return fp[n] = (dp[n-2] + func(n-1) % 1000000007);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2] + (dp[i - 1] + 2 * func(i))) % 1000000007;
    }

    printf("%ld", dp[n]);
    return 0;
}


// dp[n] = dp[n-1] + dp[n-2] + (dp[n-1] + 2*func())
//              |       =          :     ㅛ ㅠ ㅗ ㅜ


/*
n=0  1
n=1  2
n=2  7
|| :|   =   |: ::  ㅛ ㅠ func(2) = 1

n=3
ㅁㅁㅇ    func(3) = dp(3-2) + 1
ㅇㅁㅁ

*/