// https://www.acmicpc.net/problem/1765
#include <iostream>
using namespace std;

int enemyTree[1001][1001];
int friendTree[1001];
int chk[1001];

int find(int x, int* tree)
{
    if(tree[x] == x) return x;
    return tree[x] = find(tree[x], tree);
}

void merge(int x, int y, int* tree)
{
    x = find(x, tree);
    y = find(y, tree);
    if(x == y) return;
    tree[y] = x;
}


int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        friendTree[i] = i;
        for(int j = 1; j <= n; ++j) {
            enemyTree[i][j] = j;
        }
    }

    for(int i = 1; i <= m; ++i)
    {
        char status;
        int x, y;
        cin >> status >> x >> y;

        if(status == 'E') {
            merge(x, y, enemyTree[x]);
            merge(y, x, enemyTree[y]);
        }
        else { // status == 'F'
            merge(x, y, friendTree);
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        int sw = 0;
        for(int j = 1; j <= n; ++j)
        {
            if(i != j && enemyTree[i][j] == i)
            {
                if(sw > 0) merge(sw, j, friendTree);
                sw = j;
            }
        }
    }

    int answer = 0;
    for(int i = 1; i <= n; ++i) {
        if(chk[find(i, friendTree)]++ == 0) ++answer;
    }
    
    cout << answer;
}