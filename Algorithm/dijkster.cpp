#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
typedef pair<int, int> pii;

vector<vector<pii>> adj_list()
{
    int ver, eag;
    cin >> ver >> eag;
    vector<vector<pii>> graph(N);

    for (auto i = 0; i < eag; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    return graph;
}

auto graph = adj_list();
vector<int> vis(N, false);
vector<int> dis(N, INT_MAX);

void bfs(int st)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vis[st] = true;

    dis[st] = 0;
    pq.push({dis[st], st});

    while (!pq.empty())
    {
        int u = pq.top().second;

        pq.pop();
        vis[u] = true;

        for (const auto& i : graph[u])
        {
            if (vis[i.second]) continue;

            int w = i.first;
            int v = i.second;

            if (dis[v] > w + dis[u])
            {
                dis[v] = w + dis[u];
                pq.push({dis[v], v});
            }
        }
    }
}


int main()
{
    bfs(1);
    for (auto i = 0; i < graph.size(); i++)
    {
        if (graph[i].empty()) continue;
        cout << i << " : " << dis[i] << endl;
    }

    return 0;
}
