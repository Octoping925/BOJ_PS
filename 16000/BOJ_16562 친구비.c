// https://www.acmicpc.net/problem/16562
#include <stdio.h>

int n, m, k;
int price[10010];
int tree[10010];
int chk[10010];

int min(int x, int y) {
    return x < y ? x : y;
}

int find(int x) {
    if(tree[x] == x) return x;
    return tree[x] = find(tree[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    tree[x] = y;
    price[y] = min(price[x], price[y]);
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &price[i]);
        tree[i] = i;
    }

    for(int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        merge(x, y);
    }

    int answer = 0;
    for(int i = 1; i <= n; ++i) {
        if(!chk[find(i)]++) {
            answer += price[find(i)];
        }
    }

    if(answer > k) printf("Oh no");
    else printf("%d", answer);
}