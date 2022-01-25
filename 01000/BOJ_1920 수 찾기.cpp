// https://www.acmicpc.net/problem/1920
#include <stdio.h>
#include <algorithm>

int n, m;
int* arr;

void find(int x, int left, int right)
{
    int half = (left + right) / 2;
    if(x == arr[half]) printf("1\n");
    else if(left == right) printf("0\n");
    else if(x < arr[half]) find(x, left, half);
    else find(x, half + 1, right);
}

int main()
{
    scanf("%d" , &n);
    arr = new int[n];
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    std::sort(arr, arr+n);

    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        int k;
        scanf("%d", &k);
        find(k, 0, n - 1);
    }
}