// https://www.acmicpc.net/problem/14428
#include <stdio.h>

int segtree[1000010], a[1000010];
int x, y, z;

int min(int q, int w)
{ 
    if(a[q] < a[w]) return q;
    if(a[q] > a[w]) return w;
    return q < w ? q : w;
}

int init(int start, int end, int node)
{
    if(start == end) return segtree[node] = start;
    int mid = (start + end) / 2;
    return segtree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int getMin(int start, int end, int node, int left, int right)
{
    if(right < start || left > end) return y;
    if(left <= start && end <= right) return segtree[node];

    int mid = (start + end) / 2;
    return min(getMin(start, mid, node * 2, left, right), getMin(mid + 1, end, node * 2 + 1, left, right));
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
    
    init(1, n, 1);
    
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &x, &y, &z);
        if(x == 1) {
            a[y] = z;
            change(1, n, 1, y);
        }
        else printf("%d\n", getMin(1, n, 1, y, z));
    }
}