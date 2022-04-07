// https://www.acmicpc.net/problem/1005
#include <stdio.h>

int arr[1010];
int dp[1010];
int map[1010][100010];
int n, k;

int max(int x, int y) {
    return x > y ? x : y;
}

// 한 노드의 총 건설 시간은, 자신을 연결하고 있는 노드들의 건설시간의 최대값에 자기 건설시간을 더한 것과 같다
int dfs(int node){
    if(dp[node] > -1) return dp[node];

    int value = 0;
    for(int i = 1; i <= map[node][0]; ++i) {
        value = max(dfs(map[node][i]), value);
    }
    return dp[node] = value + arr[node];
}

int main()
{
    int testcase;
    scanf("%d", &testcase);

    while(testcase--) {
        scanf("%d %d", &n, &k);

        for(int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
            dp[i] = -1;

            while(map[i][0] > 0) {
                map[i][map[i][0]--] = 0;
            }
        }

        // map[x][y] = 1로 하면 연결점 찾는데 O(n) 걸리므로 공간복잡 포기하고 만든 방식.
        // map[i][0]에는 연결점 개수, map[i][1]부터 연결점의 좌표가 있음
        for(int i = 0; i < k; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            map[y][++map[y][0]] = x;
        }

        int final;
        scanf("%d", &final);
        printf("%d\n", dfs(final));
    }
    return 0;
}