#include <stdio.h>

int tree[1000001];
int size[1000001];
int cnt;

int find(int x) {
    if(tree[x] == x) return tree[x];
    return find(tree[x]);
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    tree[y] = x;
    size[y] += size[x];
    cnt--;
}
int explore(int x, int y) {
    if(tree[x] == x) return -1;
    if(tree[x] == y) return 1;
    return explore(tree[x], y);
}

void split(int x, int y) {
    int result = explore(x, y);
    if(result == 1) {
        tree[x] = x;
    } else {
        tree[y] = y;
    }
    cnt++;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= q; ++i) {
        tree[i] = i;
        size[i] = 1;
        ++cnt;
    }

    while(n--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1) {
            merge(b, c);
            printf("%d\n", cnt);
        }
        else {
            split(b, c);
            printf("%d\n", cnt);
        }
    }
}