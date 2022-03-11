// https://www.acmicpc.net/problem/2042
#include <stdio.h>

long long segtree[3000010], a[1000010];
long long x, y, z;

long long init(int start, int end, int node)
{
    if(start == end) return segtree[node] = a[start];
    int mid = (start + end) / 2;
    return segtree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long getSum(int start, int end, int node, int left, int right)
{
    if(right < start || left > end) return 0;
    if(left <= start && end <= right) return segtree[node];

    int mid = (start + end) / 2;
    return getSum(start, mid, node * 2, left, right) + getSum(mid + 1, end, node * 2 + 1, left, right);
}

long long change(int start, int end, int node, int idx)
{
    if(idx < start || idx > end) return segtree[node];
    if(start == idx && end == idx) return segtree[node] = a[idx];

    int mid = (start + end) / 2;
    return segtree[node] = change(start, mid, node * 2, idx) + change(mid + 1, end, node * 2 + 1, idx);
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    
    init(1, n, 1);
    
    for(int i = 0; i < m + k; ++i)
    {
        scanf("%lld", &x);
        if(x == 1) {
            scanf("%lld %lld", &y, &z);
            a[y] = z;
            change(1, n, 1, y);
        }
        else {
            scanf("%lld %lld", &y, &z);
            printf("%lld\n", getSum(1, n, 1, y, z));
        }
    }
}
