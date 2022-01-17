// https://www.acmicpc.net/problem/9663
#include <stdio.h>

int n;

int nqueen(int ypos, int now, int arr[])
{
    int sum = 0;
    
    for(int i = 1; i < now; ++i)
    {
        if(arr[i] == ypos) return 0;
        if((ypos - arr[i]) == (now - i) || (ypos - arr[i]) == (i - now)) return 0;
    }
    
    arr[now] = ypos;
    
    if(now == n)
        return 1;

    for(int i = 1; i <= n; ++i)
        sum += nqueen(i, now + 1, arr);
        
    return sum;
}

int main ()
{
    int arr[17] = { 0, };
    
    scanf("%d", &n);
    printf("%d", nqueen(0, 0, arr));
    
    return 0;
}
