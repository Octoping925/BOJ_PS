// https://www.acmicpc.net/problem/20040
#include <stdio.h>

int tree[500010];
int n, m;

int find(int x) {
    if(tree[x] == x) return x;
    return tree[x] = find(tree[x]);
}

// 이미 같은 그룹인 애를 또 머지하려하면 사이클
int merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return 1;
    tree[x] = y;
    return 0;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        tree[i] = i;
    }

    int answer = 0;
    for(int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(merge(x, y)) {
            answer = i;
            break;
        }
    }

    printf("%d", answer);
    return 0;
}