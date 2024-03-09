#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, e;

vector<vector<pii>> adj_list()
{
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

vi dis(N, INT_MAX);
auto graph = adj_list();

void bfs(int st)
{
    dis[st] = 0;

    for (auto j = 0; j < n - 1; j++)
    {
        bool flag = false;
        for (auto u = 1; u < graph.size(); u++)
        {
            if (graph[u].empty()) continue;

            for (const auto& i : graph[u])
            {
                int w = i.first;
                int v = i.second;
                if (dis[u] != INT_MAX and dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    flag = true;
                }
            }
        }
        if (!flag) return;
    }
}
int main()
{
    bfs(1);
    for (auto i = 1; i <= n; i++)
    {
        if (dis[i] == INT_MAX) cout << 30000 << " ";
        else cout << dis[i] << " ";
    }

    return 0;
}
