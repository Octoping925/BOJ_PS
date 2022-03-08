// https://www.acmicpc.net/problem/7511
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
    int testcase;
    scanf("%d", &testcase);
    for(int tc = 1; tc <= testcase; ++tc)
    {
        printf("Scenario %d:\n", tc);

        int n;
        scanf("%d", &n);

        int k;
        scanf("%d", &k);

        for(int i = 0; i <= n; ++i)
            tree[i] = i;

        for(int i = 0; i < k; ++i)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            merge(x, y);
        }

        int m;
        scanf("%d", &m);
        for(int i = 0; i < m; ++i)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", find(x) == find(y));
        }
        printf("\n");
    }
}