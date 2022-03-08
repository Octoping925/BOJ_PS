// https://www.acmicpc.net/problem/17352
#include <stdio.h>

int tree[300010];

int find(int x)
{
    if(tree[x] == x) return x;
    return tree[x] = find(tree[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;
    tree[y] = x;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i) tree[i] = i;
    for(int i = 0; i < n-2; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        merge(x, y);
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = i + 1; j <= n; ++j)
        {
            if(find(i) != find(j))
            {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
}