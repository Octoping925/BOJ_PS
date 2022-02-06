// https://www.acmicpc.net/problem/15352
#include <stdio.h>
#include <stdlib.h>

typedef struct XY {
    int val, L, R;
} xy;

typedef struct NODE {
    int size, to;
} node;

int isSame(xy a, xy b) { return a.val == b.val; }

int n, k;
xy *FAN;
node *TREE;

int find(int x)
{
    while(TREE[x].to == x) return x;
    return TREE[x].to = find(TREE[x].to);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(TREE[x].size < TREE[y].size) {
        TREE[y].size += TREE[x].size;
        TREE[x].to = y;
    }
    else {
        TREE[x].size += TREE[y].size;
        TREE[y].to = x;
    }
}

void delete(int x)
{
    --TREE[find(x)].size;
    FAN[x].val = 0;

    int left = FAN[x].L, right = FAN[x].R;
    if(right != -1) FAN[right].L = left;
    if(left != -1) FAN[left].R = right;

    if(isSame(FAN[left], FAN[right]))
        merge(left, right);
}

int main()
{
    scanf("%d %d", &k, &n);
    TREE = malloc(sizeof(node) * (n + 3));
    FAN = malloc(sizeof(xy) * (n + 3));

    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &FAN[i].val);
        FAN[i].L = i - 1;
        FAN[i].R = i + 1;
        TREE[i].to = i;
        TREE[i].size = 1;
        if(isSame(FAN[i], FAN[i - 1])) merge(i, i - 1);
    }
    FAN[1].L = FAN[n].R = -1;


    int q;
    long long gift = 0;
    scanf("%d", &q);
    for(int i = 0; i < q; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if(a == 1) delete(b);
        else gift += TREE[find(b)].size;
    }

    printf("%lld", gift);
    return 0;
}