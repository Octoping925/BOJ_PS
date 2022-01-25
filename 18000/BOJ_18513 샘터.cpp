#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int *lake;
vector<int> checked;

// 큐 만들고 맨 처음에 lake들 insert.
// 큐 pop하고 양 옆을 큐에 insert 반복.

int find(int x)
{
    for(int i : checked)
        if(x == i)
            return 1;
    return 0;
}

int main()
{
    scanf("%d %d", &n, &k);
    lake = new int[n+1];
    queue<int> home;

    for(int i = 0; i < n; ++i) {
        scanf("%d", &lake[i]);
        home.push(lake[i]);
        checked.push_back(lake[i]);
    }

    int cnt = 0;
    int unhappy = 0;
    int dis = 1;

    while(cnt < k)
    {
        int len = home.size();
        for(int i = 0; i < len; ++i)
        {
            int p = home.front();
            home.pop();

            if(!find(p-1)) // 큐 안에 p-1이 없으면
            {
                home.push(p-1);
                checked.push_back(p-1);
                unhappy += dis;
                ++cnt;
            }
            
            if(cnt == k) break;

            if(!find(p+1)) // 큐 안에 p+1이 없으면
            {
                home.push(p+1);
                checked.push_back(p+1);
                unhappy += dis;
                ++cnt;
            }
        }
        ++dis;
    }

    printf("%d", unhappy);
}