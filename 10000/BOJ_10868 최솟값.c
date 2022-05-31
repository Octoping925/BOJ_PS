// https://www.acmicpc.net/problem/10868
#include <stdio.h>

int segtree[400000], arr[400000];

int min(int x, int y) {
    return x < y ? x : y;
}

int init(int start, int end, int node)
{
    if(start == end) return segtree[node] = arr[start];
    int mid = (start + end) / 2;
    return segtree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int getResult(int start, int end, int node, int left, int right)
{
    if(right < start || left > end) return 1000000001;
    if(left <= start && end <= right) return segtree[node];

    int mid = (start + end) / 2;
    return min(getResult(start, mid, node * 2, left, right), getResult(mid + 1, end, node * 2 + 1, left, right));
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
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", getResult(1, n, 1, x, y));
    }

    return 0;
}