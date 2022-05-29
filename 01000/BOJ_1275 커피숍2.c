// https://www.acmicpc.net/problem/1275
#include <stdio.h>

long long segtree[400000], arr[400000];

long long init(long long start, long long end, long long node)
{
    if(start == end) return segtree[node] = arr[start];
    int mid = (start + end) / 2;
    return segtree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long getResult(long long start, long long end, long long node, long long left, long long right)
{
    if(right < start || left > end) return 0;
    if(left <= start && end <= right) return segtree[node];

    int mid = (start + end) / 2;
    return getResult(start, mid, node * 2, left, right) + getResult(mid + 1, end, node * 2 + 1, left, right);
}

long long change(long long start, long long end, long long node, long long idx)
{
    if(idx < start || idx > end) return segtree[node];
    if(start == idx && end == idx) return segtree[node] = arr[idx];

    int mid = (start + end) / 2;
    return segtree[node] = change(start, mid, node * 2, idx) + change(mid + 1, end, node * 2 + 1, idx);
}

void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    init(1, n, 1);

    while(m--) {
        int x, y, a, b;
        scanf("%d %d %d %d", &x, &y, &a, &b);
        if(x > y) swap(&x, &y);
        printf("%lld\n", getResult(1, n, 1, x, y));
        arr[a] = b;
        change(1, n, 1, a);
    }

    return 0;
}
