// https://www.acmicpc.net/problem/11505
#include <stdio.h>

int segtree[4000000], arr[1000010];

long long init(int start, int end, int node)
{
    if(start == end) return segtree[node] = arr[start];
    int mid = (start + end) / 2;
    return segtree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % 1000000007;
}

long long getResult(int start, int end, int node, int left, int right)
{
    if(right < start || left > end) return 1;
    if(left <= start && end <= right) return segtree[node];

    int mid = (start + end) / 2;
    return (getResult(start, mid, node * 2, left, right) * getResult(mid + 1, end, node * 2 + 1, left, right)) % 1000000007;
}

long long change(int start, int end, int node, int idx)
{
    if(idx < start || idx > end) return segtree[node];
    if(start == idx && end == idx) return segtree[node] = arr[idx];

    int mid = (start + end) / 2;
    return segtree[node] = (change(start, mid, node * 2, idx)  * change(mid + 1, end, node * 2 + 1, idx)) % 1000000007;
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    init(1, n, 1);

    for(int i = 0; i < m+k; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(x == 1) {
            arr[y] = z;
            change(1, n, 1, y);
        }
        else {
            printf("%d\n", getResult(1, n, 1, y, z));
        }
    }

    return 0;
}
