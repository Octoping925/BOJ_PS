// https://www.acmicpc.net/problem/14427
#include <stdio.h>
//#include <algorithm>

int segtree[1000010], a[1000010];
int x, y, z;

int min(int q, int w)
{
    return q < w ? q : w;
}

int init(int start, int end, int node)
{
    if(start == end) return segtree[node] = a[start];
    int mid = (start + end) / 2;
    return segtree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int change(int start, int end, int node, int idx)
{
    if(idx < start || idx > end) return segtree[node];
    if(start == idx && end == idx) return segtree[node];

    int mid = (start + end) / 2;
    return segtree[node] = min(change(start, mid, node * 2, idx), change(mid + 1, end, node * 2 + 1, idx));
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    
    std::sort(a+1, a+n+1);
    init(1, n, 1);
    
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d", &x);
        if(x == 1) {
            scanf("%d %d", &y, &z);
            a[y] = z;
            change(1, n, 1, y);
        }
        else printf("%d\n", segtree[1]);
    }
}