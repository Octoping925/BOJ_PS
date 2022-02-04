// https://www.acmicpc.net/problem/10814
#include <stdio.h>

int n, k;
int arr[1000010], xy[1000010][2], tree[1000010], size[1000010];

int find(int x)
{
    while(tree[x] == x) return x;
    return tree[x] = find(tree[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(size[x] < size[y]) {
        size[y] += size[x];
        tree[x] = y;
    }
    else {
        size[x] += size[y];
        tree[y] = x;
    }
    
}

void delete(int x)
{
    int left = xy[x][0], right = xy[x][1];
    
    xy[right][0] = left;
    xy[left][1] = right;

    if(arr[left] == arr[right])
        merge(left, right);

    size[find(x)]--;
}

int main()
{
    scanf("%d %d", &k, &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
        xy[i][0] = i - 1;
        xy[i][1] = i + 1;
        tree[i] = i;
        size[i] = 1;
        if(arr[i] == arr[i - 1]) merge(i, i-1);
    }
    xy[1][0] = xy[n][1] = -1;

    int q;
    long long gift = 0;
    scanf("%d" ,&q);
    for(int i = 0; i < q; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if(a == 1) {
            //arr[b] = 0;
            delete(b);
        }
        else {
            gift += (long long)size[find(b)];
        }
        for(int j = 1; j <= n; ++j) printf("%d ", arr[j]);
        printf("\n");
        for(int j = 1; j <= n; ++j) printf("%d ", xy[j][0]);
        printf("\n");
        for(int j = 1; j <= n; ++j) printf("%d ", xy[j][1]);
        printf("\n");
        for(int j = 1; j <= n; ++j) printf("%d ", tree[j]);
        printf("\n");
        for(int j = 1; j <= n; ++j) printf("%d ", size[j]);
        printf("\n\n");
    }
    
    printf("\n\n");
    printf("%d", gift);
}