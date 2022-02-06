// https://www.acmicpc.net/problem/15352
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, k;
int* parents, arr, left, right;

int find(int x)
{
    if(parents[x] < 0) return x;
    return parents[x] = find(parents[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;

    int h = parents[x] < parents[y] ? x : y;
    int l = x + y - h;

    parents[h] += parents[l];
    parents[l] = h;
}

int main()
{
    scanf("%d %d", &k, &n);
    parents = malloc(sizeof(int) * (n + 3));
    memset(parents, -1, (n+3)*sizeof(int));

    arr = malloc(sizeof(int) * (n + 3));
    left = malloc(sizeof(int) * (n + 3));
    right = malloc(sizeof(int) * (n + 3));

    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
        if(arr[i] == arr[i - 1])) merge(i, i - 1);
        left[i] = i - 1;
        right[i] = i + 1;
    }
    left[1] = right[n] = -1;


    long long sum = 0;
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if(a == 2) sum -= parents[find(b)];
        else {
            ++parents[find(b)];
            int lower = left[b]
            int higher = right[b];

            if(lower != -1 && higher != -1 && arr[lower] == arr[higher])
                merge(lower, higher);

            if(lower != -1) right[lower] = higher;
            if(higher != -1) left[higher] = lower;
        }
    }

    printf("%lld", sum);
    return 0;
}