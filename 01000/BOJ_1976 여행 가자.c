// https://www.acmicpc.net/problem/1976
#include <stdio.h>

int tree[210];

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
    scanf("%d\n%d", &n, &m);
    
    for(int i = 1; i <= n; ++i)
        tree[i] = i;
    
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int t;
            scanf("%d", &t);
            if(t == 1) {
                merge(i, j);
            }
        }
    }

    int root;
    for(int i = 1; i <= m; ++i)
    {
        int node;
        scanf("%d", &node);
        if(i == 1) root = find(node);
        else if(find(node) != root)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}