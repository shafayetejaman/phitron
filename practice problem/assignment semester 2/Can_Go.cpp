#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;
typedef pair<long long, long long> pii;
typedef vector<long long> vi;

vector<vector<pii>> adj_list()
{
    int n, e;
    cin >> n >> e;

    vector<vector<pii>> graph(N);

    for (auto i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({w, v});
    }

    return graph;
}

vi dis(N, LONG_LONG_MAX);
auto graph = adj_list();

void bfs(long long s)
{
    vector<bool> vis(N, false);
    dis[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        long long u = pq.top().second;
        pq.pop();

        vis[u] = true;

        for (auto& i : graph[u])
        {
            long long v = i.second;
            long long w = i.first;
            if (vis[v]) continue;

            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main()
{
    long long s, d, t, w;
    cin >> s >> t;
    bfs(s);

    while (t--)
    {
        cin >> d >> w;

        if (dis[d] <= w and w != LONG_LONG_MAX) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}