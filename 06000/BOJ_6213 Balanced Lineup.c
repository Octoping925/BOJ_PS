// https://www.acmicpc.net/problem/6213
#include <stdio.h>

int segtreeMin[200000], segtreeMax[200000], arr[50010];

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int init(int start, int end, int node)
{
    if(start == end) return segtreeMin[node] = arr[start];
    int mid = (start + end) / 2;
    return segtreeMin[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int getResult(int start, int end, int node, int left, int right)
{
    if(right < start || left > end) return 1000000001;
    if(left <= start && end <= right) return segtreeMin[node];

    int mid = (start + end) / 2;
    return min(getResult(start, mid, node * 2, left, right), getResult(mid + 1, end, node * 2 + 1, left, right));
}

int init2(int start, int end, int node)
{
    if(start == end) return segtreeMax[node] = arr[start];
    int mid = (start + end) / 2;
    return segtreeMax[node] = max(init2(start, mid, node * 2), init2(mid + 1, end, node * 2 + 1));
}

int getResult2(int start, int end, int node, int left, int right)
{
    if(right < start || left > end) return 0;
    if(left <= start && end <= right) return segtreeMax[node];

    int mid = (start + end) / 2;
    return max(getResult2(start, mid, node * 2, left, right), getResult2(mid + 1, end, node * 2 + 1, left, right));
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    init(1, n, 1);
    init2(1, n, 1);

    while(m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", getResult2(1, n, 1, x, y) - getResult(1, n, 1, x, y));
    }

    return 0;
}
