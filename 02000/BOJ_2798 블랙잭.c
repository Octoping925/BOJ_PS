// https://www.acmicpc.net/problem/2798
#include <stdio.h>

int arr[110];
int n, m;
int answer;


void func(int x, int sum, int depth)
{
    if(sum > m) return;
    if(x > n) return;
    
    if(depth == 3)
    {
        if(sum >= answer) answer = sum;
        return;
    }
    
    func(x + 1, sum + arr[x + 1], depth + 1);
    func(x + 1, sum, depth);
}

int main()
{
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    
    func(0, 0, 0);
    
    printf("%d", answer);
    
    return 0;
}