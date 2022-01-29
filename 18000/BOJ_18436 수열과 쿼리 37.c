// https://www.acmicpc.net/problem/18436
#include <stdio.h>

int segtree[1000010], a[1000010];

int init(int start, int end, int node)
{
    if(start == end) return segtree[node] = a[start] % 2; // 홀수면 1, 짝수면 0
    int mid = (start + end) / 2;
    return segtree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int getHolsuCnt(int start, int end, int node, int left, int right)
{
    if(right < start || left > end) return 0;
    if(left <= start && end <= right) return segtree[node];

    int mid = (start + end) / 2;
    return getHolsuCnt(start, mid, node * 2, left, right) + getHolsuCnt(mid + 1, end, node * 2 + 1, left, right);
}

int change(int start, int end, int node, int idx)
{
    if(idx < start || idx > end) return segtree[node];
    if(start == end) return segtree[node] = a[idx] % 2;

    int mid = (start + end) / 2;
    return segtree[node] = change(start, mid, node * 2, idx) + change(mid + 1, end, node * 2 + 1, idx);
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
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(x == 1) {
            a[y] = z;
            change(1, n, 1, y);
        }
        else {
            int holcnt = getHolsuCnt(1, n, 1, y, z);
            if(x == 2) printf("%d\n", z - y + 1 - holcnt);
            else printf("%d\n", holcnt);
        }
    }
}