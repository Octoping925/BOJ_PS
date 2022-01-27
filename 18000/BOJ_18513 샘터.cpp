#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int *lake;
vector<int> checked;
queue<int> home;

// 큐 만들고 맨 처음에 lake들 insert.
// 큐 pop하고 양 옆을 큐에 insert 반복.

int find(int x)
{
    int sum = 3;
    for(int i : checked) {
        if(x-1 == i) sum -= 1; //p+1
        if(x+1 == i) sum -= 2; //p-1
    }
        
    return sum;
}

int main()
{
    scanf("%d %d", &n, &k);
    lake = new int[n+1];

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

            int res = find(p);
            switch(res) {
                case 1:
                    home.push(p-1);
                    checked.push_back(p-1);
                    unhappy += dis;
                    ++cnt;
                    break;

                case 2:
                    home.push(p+1);
                    checked.push_back(p+1);
                    unhappy += dis;
                    ++cnt;
                    break;

                case 3:
                    home.push(p-1);
                    checked.push_back(p-1);
                    unhappy += dis;
                    ++cnt;
                    
                    if(cnt == k) break;
                    
                    home.push(p+1);
                    checked.push_back(p+1);
                    unhappy += dis;
                    ++cnt;
            }
            if(cnt == k) break;
        }
        ++dis;
    }
    
    printf("%d", unhappy);
}