// https://www.acmicpc.net/problem/1916
// https://www.acmicpc.net/problem/1916
#include <iostream>
#include <vector>
#include <queue>

#define INF 999999999
using namespace std;

vector<pair<int, int>> dijk[20010];
int dist[20010];
int visited[20010];

int main()
{
    int v, e;
    cin >> v >> e;

    for(int i = 0; i < e; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        dijk[x].push_back(pair<int, int>(y, z));
    }
    
    int k, l;
    cin >> k >> l;
    for(int i = 0; i <= v; ++i) dist[i] = INF;
    dist[k] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(pair<int, int>(0, k));
    while(!pq.empty()) {
        int cur;
        do{
            cur = pq.top().second;
            pq.pop();
        } while(!pq.empty() && visited[cur]);

        if(visited[cur]++) break;

        for(pair<int, int> p: dijk[cur]) {
            int next = p.first;
            int d = p.second;

            if(dist[next] > dist[cur] + d) {
                dist[next] = dist[cur] + d;
                pq.push(pair<int, int>(dist[next], next));
            }
        }
    }

    cout << dist[l];
}