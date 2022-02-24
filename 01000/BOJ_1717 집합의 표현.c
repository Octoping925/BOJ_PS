// https://www.acmicpc.net/problem/1717
#include <stdio.h>

int tree[1000010];

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
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= n; ++i)
        tree[i] = i;
    
    for(int i = 0; i < m; ++i)
    {
        int q, x, y;
        scanf("%d %d %d", &q, &x, &y);
        if(q == 0) merge(x, y);
        else
        {
            if(find(x) == find(y)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}