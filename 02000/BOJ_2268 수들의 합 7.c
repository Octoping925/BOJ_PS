// https://www.acmicpc.net/problem/2268
#include <stdio.h>

long long segtree[4000000], arr[1000010];

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

    while(m--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(x == 0) {
            if(y > z) swap(&y, &z);
            printf("%lld\n", getResult(1, n, 1, y, z));
        }
        else {
            arr[y] = z;
            change(1, n, 1, y);
        }
    }

    return 0;
}
