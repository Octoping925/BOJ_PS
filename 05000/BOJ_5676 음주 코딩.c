// https://www.acmicpc.net/problem/5676
#include <stdio.h>

int segtree[40000], a[40000];

int init(int start, int end, int node)
{
    if(start == end) return segtree[node] = a[start];
    int mid = (start + end) / 2;
    return segtree[node] = init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1);
}

int getResult(int start, int end, int node, int left, int right)
{
    if(right < start || left > end) return 1;
    if(left <= start && end <= right) return segtree[node];

    int mid = (start + end) / 2;
    return getResult(start, mid, node * 2, left, right) * getResult(mid + 1, end, node * 2 + 1, left, right);
}

int change(int start, int end, int node, int idx)
{
    if(idx < start || idx > end) return segtree[node];
    if(start == idx && end == idx) return segtree[node] = a[idx];

    int mid = (start + end) / 2;
    return segtree[node] = change(start, mid, node * 2, idx) * change(mid + 1, end, node * 2 + 1, idx);
}

int setting(int x) {
    return x == 0 ? 0 : x > 0 ? 1 : -1;
}

int main()
{
    int n, m;
    while(~scanf("%d", &n)) {
        scanf("%d", &m);
        for(int i = 1; i <= n; ++i) {
            int p;
            scanf("%d", &p);
            a[i] = setting(p);
        }

        init(1, n, 1);

        for(int i = 0; i < m; ++i)
        {
            char x;
            int y, z;
            scanf(" %c %d %d", &x, &y, &z);
            if(x == 'C') {
                a[y] = setting(z);
                change(1, n, 1, y);
            }
            else {
                int result = getResult(1, n, 1, y, z);
                if(result == 0) printf("0");
                else printf("%c", result > 0 ? '+' : '-');
            }
        }
        printf("\n");
        
        
        for(int i = 0; i < 40000; ++i) {
            segtree[i] = 0;
            a[i] = 0;
        }
    }
}
